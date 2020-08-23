package Assignment02;

public abstract class Oil {

	private String company;
	private String oilType;
	private double consumerPrice;
	
	Oil(String name, String oil_type) // two parameter - constructor
	{
		this.company = name;
		this.oilType = oil_type;
		this.consumerPrice = 0;
	}
	
	/*
	public String Get_name()
	{
		return company;
	}
	*/
	
	public double Get_comsumerPrice() // Getter method of consumer price
	{
		return consumerPrice;
	}
	
	public void Set_consumberPrice(double price) // setter method of consumer price
	{
		this.consumerPrice = price;
		//System.out.println(this.consumerPrice + "***");
	}
	
	public String toString() // to string method
	{
		String str = "";
		str += "company : " + this.company.toString() + "\n";
		str += "oil type :" + this.oilType.toString() + "\n";
		return str;
	}
	
	public abstract double getOilPrice(); // abstract method : using derived class
}
