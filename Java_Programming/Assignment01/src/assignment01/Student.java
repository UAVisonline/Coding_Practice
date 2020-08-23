package assignment01;

import java.util.Calendar;
import java.util.Scanner; //

public class Student {
	private String studentName;
	private int studentCode;
	Lecture timeTable[][] = new Lecture[10][5];

	public enum DAYS {
		MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY //ENUM DAYS to use some method
	}

	public Student() { //default constructor
		for(int i = 0;i<10;i++)
		{
			for(int j=0;j<5;j++)
			{
				timeTable[i][j] = new Lecture(); // assign none lecture timetable
			}
		}
	}

	public Student(String studentName, int studentCode) { //Constructor
		this();
		this.setStudentName(studentName);
		this.setStudentCode(studentCode);
	}

	public String getStudentName() {
		return this.studentName.toString();
	}

	public void setStudentName(String studentName) {
		this.studentName = studentName;
	}

	public int getStudentCode() {
		return this.studentCode;
	}

	public void setStudentCode(int studentCode) {
		this.studentCode = studentCode;
	}

	public void setScheduleInformation(Lecture lecture) { //set schedule method
		if(lecture == null) return;
		else if(lecture.getEnrolled() >= lecture.getMaxEnrolled()) //max enrolled lecture so you cannot assign this lecture
		{
			System.out.println("���Ǹ� �߰��� �� �����ϴ�. : �ִ� ���� �ο� �ʰ�");
			return;			
		}
		else // assign lecture
		{
			
			DAYS[] day = DAYS.values(); //ENUM DAYS array
			for(int i=0;i<day.length;i++) //check the right day
			{
				if(lecture.getDay().equalsIgnoreCase(day[i].toString())) // correct the ENUM Array and lecture's day
				{
					if(this.timeTable[lecture.getTime()-1][i].checkLecture()) //timetable empty
					{
						
						this.timeTable[lecture.getTime()-1][i] = lecture; //shallow copy to timetable lecture <- lecture
						this.timeTable[lecture.getTime()-1][i].incEnrolled(); //increase enrolled
						//Shallow copy make privacy leak but method deleteschedule() use lecture object to decrease enrolled, so I use shallow copy
						// ** Write method and manage it!!! You can't make the gap to use this shallow copy, privacy leak. If you don't do that, privacy leak break your all code!!! **
						
						//this.timeTable[lecture.getTime()-1][i] = new Lecture(lecture.getDay(), lecture.getTime(), lecture.getLectureName(), lecture.getProfessor(), lecture.getRoomNumber(), lecture.getMaxEnrolled());
						//lecture.incEnrolled();
						
						System.out.println("�ð��� ���������� �߰��Ǿ����ϴ�.");
						break;
						//this.timeTable[lecture.getTime()-1][i].incEnrolled(); //
					}
					else //timetable not empty
					{
						System.out.println("���Ǹ� �߰��� �� �����ϴ�. : �ش� �ð�ǥ �̹� ����");
						return;	
					}
				}
				else if(!lecture.getDay().equalsIgnoreCase(day[i].toString()) && i==day.length-1) //can't find lecture's day
				{
					
					if(day.toString().equalsIgnoreCase("Saturday") || day.toString().equalsIgnoreCase("Sunday"))
					{
						System.out.println("������̳� �Ͽ��Ͽ��� ���ǰ� �߰��� �� �����ϴ�..");
					}
					else
					{
						System.out.println("�ش� ���ǿ� ������ �߸��� ������ �νĵǾ����ϴ�.");
					}
				}
			}
		}
		
	}
	public String showTimetable() {
		String print = "  ";
		print += String.format("%25s","MONDAY");
		print += String.format("%25s","TUESDAY");
		print += String.format("%25s","WEDNESDAY");
		print += String.format("%25s","THURSDAY");
		print += String.format("%25s\n","FRIDAY");
		for(int i = 0;i<10;i++)
		{
			if((i+1)/10==0) print += " " + (i+1); // lecture time 1~9
			else print += "" + (i+1); //lecture time 10
			for(int j = 0;j<5;j++) 
			{
				print += String.format("%25s",this.timeTable[i][j].getLectureName());
			}
			print += "\n";
		}
		return print; //return timetable
	}

	public boolean equals(Student stu) {
		if(stu == null) return false;
		else if(this.getClass() != stu.getClass()) return false;
		else
		{
			return (this.showTimetable().equals(stu.showTimetable())); // compare the two student's timetable
		}
	}
	
	public void deleteSchedule(String day, int period)
	{
		if(day == null) 
		{
			System.out.println("�Է°��� null���Դϴ�.");
			return;
		}
		else if(period <= 0 || period > 10) // period is not in the 1~10
		{
			System.out.println(period + "�ð��� �ð�ǥ�� �����ϴ� �ð���� ���غ���, ��ġ���� �ʴ� �ð��Դϴ�.");
			return;
		}
		else
		{
			DAYS[] days = DAYS.values();
			for(int i=0;i<days.length;i++)
			{
				if(day.toString().equalsIgnoreCase(days[i].toString())) // correct data 
				{
					if(!this.timeTable[period-1][i].checkLecture()) //if the delete schedule time table is not empty, delete it
					{
						this.timeTable[period-1][i].decEnrolled(); // decrease enrolled
						this.timeTable[period-1][i] = new Lecture(); // this timetable lecture assign none lecture
						break;
					}
					else if(this.timeTable[period-1][i].checkLecture()) // if the delete schedule is already empty
					{
						System.out.println("�ش� �ð�ǥ�� �̹� ����� �ֽ��ϴ�.");
						break;
					}
				}
				else if(!day.toString().equalsIgnoreCase(days[i].toString()) && i==days.length -1) // can not find data correctness
				{
					if(day.toString().equalsIgnoreCase("Saturday") || day.toString().equalsIgnoreCase("Sunday")) //Case of Saturday or Sunday
					{
						System.out.println(day.toString() + "�� �ش��ϴ� ������ ������ �� �ִ� ���� ������� ���մϴ�.");
					}
					else //Case of wrong day data
					{
						System.out.println(day.toString() + "�� �߸��� ���Դϴ�.");
					}
				}
			}
		}
	}
	
	public Calendar setInputDate()
	{
		Calendar cal = Calendar.getInstance(); // create object Calendar
		Scanner keyboard = new Scanner(System.in); // create object Scanner
		System.out.println("Enter the date:");
		int date = keyboard.nextInt(); // ex) 19840514, 20200519
		//keyboard.nextLine();
		
		int date_year = date/10000;
		//System.out.println("Date_Year : " + date_year);
		int date_month = (date%10000)/100;
		//System.out.println("Date_Month : " + date_month);
		int date_day = date%100;
		//System.out.println("Date_Day : " + date_day);
		
		cal.set(date_year, date_month-1, date_day); // calendar object set the year, month, date
		return cal; //return calendar object
	}
	
	public String oneDaySchedule(String day) {
		String str = "\n" + day + "\n";
		DAYS[] days = DAYS.values();
		if(day.equalsIgnoreCase("Sunday") || day.equalsIgnoreCase("Saturday")) // Case of Saturday or Sunday
		{
			for(int i=0;i<10;i++)
			{
				str += "----\n"; // None lecture here
			}
		}
		else
		{
			for(int i=0;i<days.length;i++) // Case of weekday, not weekend
			{
				if(days[i].toString().equalsIgnoreCase(day.toString())) // find the correct day
				{
					for(int j=0;j<10;j++)
					{
						str += this.timeTable[j][i].getLectureName() + "\n"; // write lecture
					}
					break;
				}
			}
		}
		return str; // return one day timetable
	}

}
