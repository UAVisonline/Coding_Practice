package selfTest;

public class MathEx {

	public static void main(String[] args) {

		int a = 60984;
		int b = 808;
		
		double x = 2.0;
		double y = 3.0;
		double r;
		
		r = Math.random()*10; // generate random double number r(0<=r<10)
		
		System.out.println("Maximum: " + Math.max(a, b)); //Find Maximum value of a,b
		System.out.println("Mininum: " + Math.min(a, b)); //Find Minimum value of a,b
		System.out.println("x^y: " + Math.pow(x,y)); // calculate x^y
		System.out.println("y^x: " + Math.pow(y,x)); // calculate y^x
		System.out.println("Radius: " + r); 
		System.out.println("Circle area: " + Math.PI*Math.pow(r,2)); //PI*r*r
		
	}

}
