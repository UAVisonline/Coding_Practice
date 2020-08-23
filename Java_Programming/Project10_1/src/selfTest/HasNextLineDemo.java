package selfTest;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import java.io.FileInputStream;
import java.io.FileOutputStream;

public class HasNextLineDemo {

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner inputStream = null;
		PrintWriter outputStream = null;
		
		try {
			/* Input File Location Example: resource\\BladeRunner.txt */
			inputStream = new Scanner(new FileInputStream("resource\\BladeRunner.txt"));
			//if(inputStream == null) throw new FileNotFoundException();

			outputStream = new PrintWriter(new FileOutputStream("resource\\NumberedRunner.txt"));
			//if(outputStream == null) throw new FileNotFoundException();
			
		} catch (FileNotFoundException e) {
			System.out.println("Problem opening files.");
			System.exit(0);
		}
		
		int i = 1;
		while(inputStream.hasNextLine())
		{
			String str = inputStream.nextLine();
			outputStream.println(i++ + " " + str);
		}
		inputStream.close();
		outputStream.close();
	}

}
