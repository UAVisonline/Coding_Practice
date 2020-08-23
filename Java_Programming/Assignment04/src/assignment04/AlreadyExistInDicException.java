package assignment04;

public class AlreadyExistInDicException extends Exception
{
	public AlreadyExistInDicException() //default constructor
	{
		super("this word already exist in dictionary");
	}

	public AlreadyExistInDicException(String str)
	{
		super(str);
	}
	
	public String getMessage() //method return error message
	{
		return "this word already exist in dictionary";
	}
}
