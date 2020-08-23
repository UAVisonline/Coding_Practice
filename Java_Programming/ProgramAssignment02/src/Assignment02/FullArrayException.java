package Assignment02;

public class FullArrayException extends Exception{ // derived class of exception class

	FullArrayException() // default construct
	{
		super();
	}
	
	FullArrayException(String str) // one parameter construct
	{
		super(str);
	}
	
	public void get_Full() // we use this method when array is full
	{
		System.out.println("List is full!");
		System.out.println("Try to expand...");
		System.out.println("How much will it expand??");
	}
}
