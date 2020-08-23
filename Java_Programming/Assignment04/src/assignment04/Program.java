package assignment04;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class Program {

	public static void main(String[] args)
	{
		DictionaryArray Dic = new DictionaryArray(); // new Class DictionaryArray object assign
		int command;
		Scanner keyboard = new Scanner(System.in);
		while(true)
		{
			System.out.println("=============Main Menu=============");
			System.out.println("(1) Add a word to dictionary");
			System.out.println("(2) Show definition of word");
			System.out.println("(3) Show word list");
			System.out.println("(4) Remove word");
			System.out.println("(5) print all contents");
			System.out.println("(6) Exit program");
			System.out.println("==================================");
			System.out.print("choose a menu : ");
			command = keyboard.nextInt(); // input command
			keyboard.nextLine();
			switch(command)
			{
			case 1:
				try
				{
					System.out.print("word : ");
					//keyboard.nextLine();
					String word = keyboard.nextLine(); // input word
					System.out.print("definition : ");
					//keyboard.nextLine();
					String definition = keyboard.nextLine(); // input definition
					Dic.insertEntry(word, definition); // insert it
				}
				catch(AlreadyExistInDicException e) 
				{
					System.out.println(e.getMessage());
				}
				break;
			case 2:
				try
				{
					System.out.println("word for searching : ");
					//keyboard.nextLine();
					String word = keyboard.nextLine(); //input word
					Dic.getDefinition(word); // search word and print definition
				}
				catch(EmptyException e)
				{
					System.out.println(e.getMessage());
				}
				catch(NotInDicException e)
				{
					System.out.println(e.getMessage());
				}
				break;
			case 3:
				try
				{
					Dic.printWords(); // print word list
				}
				catch(EmptyException e)
				{
					System.out.println(e.getMessage());
				}
				break;
			case 4:
				try
				{
					System.out.println("word to remove : "); 
					//keyboard.nextLine();
					String word = keyboard.nextLine(); //input word that you want to remove
					Dic.removeWord(word); // remove word 
				}
				catch(EmptyException e)
				{
					System.out.println(e.getMessage());
				}
				catch(NotInDicException e)
				{
					System.out.println(e.getMessage());
				}
				break;
			case 5:
				try
				{
					Dic.printAll(); // Print all word and definition
				}
				catch(EmptyException e)
				{
					System.out.println(e.getMessage());
				}
				break;
			case 6:
				System.out.println("Enter a file name : ");
				//keyboard.nextLine();
				String Filename = keyboard.nextLine(); //input file name
				//Filename = "resource\\\\" + Filename;
				try
				{
					PrintWriter writer = null;
					writer = new PrintWriter(new FileOutputStream(Filename)); //Make new file name of Filename
					ArrayList<WordDefinitionPair> temp = Dic.Return_DicList(); //new ArrayList assign
					for(int i = 0;i<temp.size();i++) // Write word and definition in File
					{
						writer.println(i+1 + ". word : " + temp.get(i).Return_Word()); 
						writer.println("   definition : " + temp.get(i).Return_Definition());
					}
					System.out.println("saved as " + Filename.toString());	// Write Finished
					writer.close(); // PrintWriter close
					System.out.println("exit program"); 
					return; //program end
				}
				catch(FileNotFoundException e) // Can found FileName
				{
					System.out.println("saved fail to " + Filename.toString()); // Save Fail
					System.out.println("exit program");
					System.exit(0);
				}
				break;
			default:
				System.out.println("Insert 1 ~ 6"); // default case
			}
		}
	}
}
