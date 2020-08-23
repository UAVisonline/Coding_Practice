package selfTest;

public class Employee {

	private String name;
	private String position = "Engineer";
	private int age;
	private int salary = 15000;
	private int vacationDays = 20;
	
	public Employee() 
	{
		
	}
	
	public Employee(String name, int age) 
	{
		this.name = name;
		this.age = age;
	}
	
	public Employee(String name, int age, String position, int salary)
	{
		this.name = name;
		this.age = age;
		this.position = position;
		this.salary = salary;
	}
	
	public Employee(String name, int age, String position, int salary, int vacationDays) 
	{
		this.name = name;
		this.age = age;
		this.position = position;
		this.salary = salary;
		this.vacationDays = vacationDays;
	}
	
	public void setSalary(int data) 
	{
		this.salary = data;
	}
	
	public void outInfo() 
	{
		System.out.println("name : " + this.name);
		System.out.println("age : " + this.age);
		System.out.println("position : " + this.position);
		System.out.println("salary : " + this.salary);
		System.out.println("vacationDays : " + this.vacationDays);
		System.out.println();
	}
	
	public String vacation(int data) 
	{
		if(this.vacationDays>=data)
		{
			this.vacationDays -= data;
			return "Possible";
		}
		else return "Impossible";
		
	}
	
	public boolean equals(Employee emp)
	{
		if(this.name.equals(emp.name) == true && this.position.equals(emp.position)== true && this.age==emp.age) return true;
		else return false;
	}
	
}
