package assignment04;

public class EmptyException extends Exception{

	public EmptyException() // default constructor
	{
		super("List is empty");
	}
	
	public EmptyException(String str)
	{
		super(str);
	}
	
	public String getMessage() //method return error message
	{
		return "List is empty";
	}
}
