package assignment03;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ElectionSim {

	private String outputFile;
	private int population;
	private Candidate[] candidates;
	private Region[] regions;
	
	public ElectionSim(String inputFile, String outputFile) { // constructor
		this.outputFile = outputFile;
		Scanner keyboard = null;
		try
		{
			keyboard = new Scanner(new FileInputStream(inputFile)); // read input File
		}
		catch (FileNotFoundException e)
		{
			System.out.println("Opening File Error");
			System.exit(0);
		}
		
		while(keyboard.hasNextLine()) // when we reach the EOF
		{
			String str = keyboard.nextLine();
			if(str.length()>10)
			{
				if(str.substring(0,10).equals("POPULATION")) // population set
				{
					this.population = Integer.parseInt(str.substring(11));
					
				}
				else if(str.substring(0,10).equals("CANDIDATES")) //candidates set
				{
					this.candidates = new Candidate[Integer.parseInt(str.substring(11))];
					for(int i =0;i<candidates.length;i++)
					{
						String name = keyboard.nextLine();
						candidates[i] = new Candidate(name,population); // assign candidate
					}
				}
			}
			
			else
			{
				
				if(str.indexOf("REGIONS")!=-1) // regions set
				{
					this.regions = new Region[Integer.parseInt(str.substring(8))];
					for(int i = 0;i<regions.length;i++)
					{
						String key = keyboard.nextLine();
						String name = key.substring(0,key.indexOf(' '));
						key = key.substring(key.indexOf(' ')+1);
						//System.out.println(key);
						int region_num = Integer.parseInt(key.substring(0,key.indexOf(' ')));
						key = key.substring(key.indexOf(' ')+1);
						//System.out.println(key);
						int region_population = Integer.parseInt(key);
						regions[i] = new Region(name,region_num,region_population,candidates); // assign region
					}
				}
			}
		}
		
		keyboard.close(); // close scanner 
	}
	
	public void saveData() {
		Arrays.sort(candidates);
		PrintWriter Writer = null;
		try
		{
			Writer = new PrintWriter(new FileOutputStream(outputFile)); // open output file, if not in resources then create it
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Writing File Error");
			System.exit(0);
		}
		for(int i =0;i<candidates.length;i++)
		{
			Writer.println("------------Candidate----------");
			Writer.println(candidates[i].toString()); // Candidates total votes
			for(int j=0;j<regions.length;j++)
			{
				Writer.println(regions[j].getRegionName() + ": " + candidates[i].toRegionString(j+1)); // candidates region votes
			}
			if(i!=candidates.length-1) Writer.println("\n==============================");
		}
		Writer.close(); // close PrintWriter
		
	}
	
	public void runSimulation() {
		
		for(int i = 0;i<regions.length;i++)
		{
			regions[i].start(); // each region start generate vote
			try
			{
				regions[i].join(); // wait until region thread die 
			}
			catch (InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		saveData(); // save data, Print output files
	}
}
