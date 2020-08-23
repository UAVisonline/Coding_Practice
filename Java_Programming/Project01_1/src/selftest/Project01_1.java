package selftest;

public class Project01_1 {
	public static void main(String[] args) {
		
		int counter , totalDistance;
		counter = 3;
		totalDistance = 15;
		
		int quotient, remainder;
		quotient = totalDistance/counter;
		remainder = totalDistance%counter;
			
		System.out.println("Quotient of totalDistance / counter: " + quotient);
		System.out.println("Remainder of totalDistance / counter: " + remainder);
	}
}
