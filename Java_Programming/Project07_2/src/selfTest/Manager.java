package selfTest;

public class Manager extends Employee{

	private int officeNum;
	private String team;
	
	public Manager(String name, int employeeNum, int officeNum, String team) {
		super(name,employeeNum);
		this.team = team;
		this.officeNum = officeNum;
	}
	
	public String toString() {
		return ("Name : " + getName() + "\nLocation : " + getDepartment() + ", " + officeNum);
	}
	
	public boolean equals(Object obj) {
		if(super.equals(obj))
		{
			Manager object = (Manager)obj;
			if(this.officeNum == object.officeNum)
			{
				if(this.team.equals(object.team)) return true;
			}
		}
		return false;
	}
}
