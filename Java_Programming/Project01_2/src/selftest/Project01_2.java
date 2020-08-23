package selftest;

public class Project01_2 {

	public static void main(String[] args) {

		String name = "hwang hui su";
		String greeting1 = "Hello", greeting2 = "nice to meet you";
		String uName = name.toUpperCase();
				
		System.out.println(greeting1 + " " + name + " " + greeting2); 
		System.out.println(name.length());
		System.out.println(name.equals(uName));
		System.out.println(name.equalsIgnoreCase(uName));
	}

}
