package selftest;

public class Chocolate_Factory {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Chocolate_Boiler a = Chocolate_Boiler.Ret_Boiler();
		Chocolate_Boiler b = Chocolate_Boiler.Ret_Boiler();
		
		a.fill();
		b.fill();
		a.boil();
		b.boil();
		a.drain();
		b.drain();
	}

}
