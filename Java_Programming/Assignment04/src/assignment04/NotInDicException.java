package assignment04;

public class NotInDicException extends Exception{
	
	public NotInDicException() // default constructor
	{
		super("this word not exist in dictionary");
	}
	
	public NotInDicException(String str)
	{
		super(str);
	}
	
	public String getMessage() //method return error message
	{
		return "this word not exist in dictionary";
	}

}
