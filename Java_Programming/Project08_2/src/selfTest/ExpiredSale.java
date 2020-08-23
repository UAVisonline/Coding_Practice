package selfTest;

public class ExpiredSale extends Sale {
	
	private double expired;
	
	public ExpiredSale() {
		super();
		setExpired(0);
	}
	
	public ExpiredSale(String theName, double thePrice, double theExpired) {
		super(theName, thePrice);
		setExpired(theExpired);
	}
	
	public void setExpired(double theExpired) {
		expired = theExpired;
	}
	
	public String toString() { return (getName() + " Price = $" + getPrice() + " Expired = " + expired + " left\n" + " Deliver Fee = $" + deliverFee()); }
	
	public double deliverFee() {
		if(this.expired>=10) return 3.0;
		else if(this.expired<10 && this.expired>=3) return 2.0;
		else if(this.expired<3 && this.expired>1) return 0.0;
		else
		{
			System.out.println("Fatal Error : expired error");
			System.exit(0);
			return -99.999;
		}
	}
	
}
