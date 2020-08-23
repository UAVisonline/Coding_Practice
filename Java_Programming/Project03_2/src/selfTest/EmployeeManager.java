package selfTest;

public class EmployeeManager {

	public static void main(String[] args)
	{
		Employee emp1 = new Employee("Walter White",42,"Manager",20000);
		Employee emp2 = new Employee("Jesse Pinkman",32,"Assistant Manager",12000,7);
		Employee emp3 = new Employee("Jimmie McGill",38);
		Employee emp4 = new Employee("Chuck McGill",40);
		Employee emp5 = new Employee("Walter White",42,"Manager",20000);
		
		emp1.setSalary(21000);
		emp1.outInfo();
		emp2.outInfo();
		System.out.println(emp3.vacation(10));
		System.out.println();
		System.out.println(emp2.vacation(10));
		System.out.println();
		emp3.outInfo();
		System.out.println(emp1.equals(emp2));
		System.out.println(emp1.equals(emp5));

	}

}
