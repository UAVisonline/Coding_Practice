package selfTest;

public class Employee {

	private String name;
	private int employeeNum;
	private String department = "No Dept";
	
	public Employee(String name, int employeeNum) {
		this.name = name;
		this.employeeNum = employeeNum;
	}
	
	public Employee(String name, int employeeNum, String deaprtment) {
		this.name = name;
		this.employeeNum = employeeNum;
		this.department = department;
	}
	
	public String getDepartment() { // accessor that department
		String ret_department = this.department.toString();
		return ret_department;
	}
	
	public String getName() { //accessor that name
		String ret_name = this.name.toString();
		return ret_name;
	}

	public void setDepartment(String department) { //mutator that set department
		this.department = department;
	}
	
	public void setName(String name) { //mutator that set name
		this.name = name;
	}
	
	public boolean equals(Employee anotherEmp) {
		if(this.employeeNum == anotherEmp.employeeNum)
		{
			if(this.name.equals(anotherEmp.name.toString())) return true;
		}
		return false;
	}
	
	public String toString() {
		return "Name : " + this.name.toString() +"\nEmp# : "+this.employeeNum;
	}
}
