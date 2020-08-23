package assignment01;

public class Lecture {
	private String day;
	private int time;
	private String lectureName;
	private String professor;
	private String roomNumber;
	private int Enrolled;
	private int maxEnrolled;
	
	
	public Lecture() // Default Lecture constructor
	{
		this.lectureName = "----"; //None lecture here
		this.professor = "None";
		this.roomNumber = "None";
		
	}
	
	public Lecture(String day, int time, String lectureName, String professor, String roomNumber, int maxEnrolled) // Lecture Constructor
	{
		this.day = day;
		this.time = time;
		this.lectureName = lectureName;
		this.professor = professor;
		this.roomNumber = roomNumber;
		this.maxEnrolled = maxEnrolled;
		this.Enrolled = 0;
		
	}
	public String getDay() { 
		return this.day.toString();
	}

	public void setDay(String day) {
		this.day = day;
	}

	public int getTime() {
		return this.time;
	}

	public void setTime(int time) {
		this.time = time;
	}

	public String getLectureName() {
		return this.lectureName.toString();
	}

	public void setLectureName(String lectureName) {
		this.lectureName = lectureName;
	}

	public String getProfessor() {
		return this.professor.toString();
	}

	public void setProfessor(String professor) {
		this.professor = professor;
	}

	public String getRoomNumber() {
		return this.roomNumber.toString();
	}

	public void setRoomNumber(String roomNumber) {
		this.roomNumber = roomNumber;
	}
	
	public int getMaxEnrolled() {
		return this.maxEnrolled;
	}
	
	public void setMaxEnrolled(int maxEnrolled) {
		this.maxEnrolled = maxEnrolled;
	}
	public int getEnrolled() {
		return this.Enrolled;
	}
	public void incEnrolled() {
		this.Enrolled++;
	}
	public void decEnrolled() {
		this.Enrolled--;
	}
	
	public boolean equals(Lecture s) {
		if(s==null) return false;
		else if(this.getClass() != s.getClass()) return false;
		else
		{
			return (this.getLectureName().equals(s.getLectureName()) && this.getProfessor().equals(s.getProfessor()) && this.getRoomNumber().equals(s.getRoomNumber()));
		}
	}

	public boolean checkLecture() { //Check method that can I assign new lecture
		if(this.getLectureName() == null) return false;
		else if(this.getLectureName().equals("----")) return true;
		else return false;
	}
	
	
}