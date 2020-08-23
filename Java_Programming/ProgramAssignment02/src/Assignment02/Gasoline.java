package Assignment02;

public class Gasoline  extends Oil{

	private int price;
	private double VAT;
	
	Gasoline(String company,int price) // constructor
	{
		super(company, "gasoline");
		this.price = price;
		VAT = 30*Math.random()/100;
		this.Set_consumberPrice((int)(price + price*VAT));
		//System.out.println(VAT);
	}


	public double getOilPrice() // set consumer price and return consumer price
	{
		//super.Set_consumberPrice(price+price*(int)VAT);
		this.Set_consumberPrice((int)(price + price*VAT));
		return super.Get_comsumerPrice();
	}

	
	public String toString() // to string override
	{
		String str = super.toString();
		str += "supply price : " + this.price + "\n";
		return str;
	}
	
}
