package selfTest;

import java.util.Scanner;//Import the library for using Scanner class

public class Project02_1 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);//Generate the Scanner class
		
		int n = 0;
		System.out.print("Enter the number: ");		
		
		n = input.nextInt(); // Using Scanner object to enter the number
		
		if(n<0) System.out.print("n is less than 0");//"n is less than 0" for n < 0
		else if(n>=0 && n<100) System.out.print("n is greater than or equal to 0 and less than 100");//"n is greater than or equal to 0 and less than 100" for 0 <= n < 100
		else System.out.print("n is greater than or equal to 100");//"n is greater than or equal to 100" for n >= 100	
		
	}

}
