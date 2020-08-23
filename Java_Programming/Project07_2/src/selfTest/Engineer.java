package selfTest;

public class Engineer extends Employee{
	private String workZone;
	private String project;
	
	public Engineer(String name, int employeeNum, String workZone, String project) {
		super(name,employeeNum);
		this.workZone = workZone;
		this.project = project;
	}
	
	public boolean equals(Object obj) {
		if(super.equals(obj))
		{
			Engineer object = (Engineer)obj;
			if(this.workZone.equals(object.workZone)) return true;
		}
		return false;
	}
	
	public String toString() {
		return ("Name : " + this.getName() + "\nEmp# : " + this.getEmployeeNum() +"\nlocation : " + this.getDepartment() + ", "+ this.workZone);
	}
}
