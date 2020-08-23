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
	
	public String getDepartment() {
		return department;
	}
	
	public String getName() {
		return name;
	}
	
	public int getEmployeeNum() {
		return this.employeeNum;
	}

	public void setDepartment(String department) {
		this.department = department;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setEmployeeNum(int employeeNum) {
		this.employeeNum = employeeNum;
	}
	
	public boolean equals(Object obj) {
		if(obj == null) return false;
		else if(obj.getClass() != this.getClass()) return false;
		else
		{
			Employee anotherEmp = (Employee)obj;
			if(this.employeeNum == anotherEmp.employeeNum)
			{
				if(this.name.equals(anotherEmp.name.toString())) return true;
			}
		}
		return false;
	}
	
	public String toString() {
		return ("Name : " + this.name + "\nEmp# : " + this.employeeNum);
	}
}
