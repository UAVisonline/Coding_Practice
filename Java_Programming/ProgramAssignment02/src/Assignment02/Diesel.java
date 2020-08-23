package Assignment02;

public class Diesel extends Oil {

	private int price;
	private double VAT;
	private double envTax;
	
	Diesel(String company,int price) // constructor
	{
		super(company, "diesel");
		this.price = price;
		VAT = 30*Math.random()/100;
		envTax = 500.0;
		this.Set_consumberPrice((int)(price + price*VAT) + envTax);
		//System.out.println((price + price*VAT) + envTax);
	}
	
	public double getOilPrice() // set consumer price and get consumer price
	{
		//super.Set_consumberPrice(price + price*(int)VAT + envTax);
		this.Set_consumberPrice((int)(price + price*VAT) + envTax);
		return super.Get_comsumerPrice();
	}
	
	public String toString() // to string override
	{
		String str = super.toString();
		str += "supply price : " + this.price + "\n";
		return str;
	}
	
}
