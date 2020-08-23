package selftest;

public class Chocolate_Boiler {

	private boolean empty;
	private boolean boiled;
	private static Chocolate_Boiler boiler = new Chocolate_Boiler();
	
	public Chocolate_Boiler()
	{
		empty = true;
		boiled = false;
	}
	
	public void fill()
	{
		if(isEmpty())
		{
			empty = false;
			boiled = false;
			System.out.println("Filling with mixture");
		}
		else System.out.println("Already filled");
		
	}
	
	public void drain()
	{
		if(!isEmpty() && isBoiled())
		{
			empty = true;
			System.out.println("Draining the mixture");
		}
		else System.out.println("Already drained");
	}
	
	public void boil()
	{
		if(!isEmpty() && !isBoiled())
		{
			boiled = true;
			System.out.println("Boiling with mixture");
		}
		else System.out.println("Already boiled");
	}
	
	public boolean isEmpty()
	{
		return empty;
	}
	
	public boolean isBoiled()
	{
		return boiled;
	}
	
	public static Chocolate_Boiler Ret_Boiler()
	{
		return boiler;
	}
}
