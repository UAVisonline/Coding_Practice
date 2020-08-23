package assignment01;

import java.util.Calendar;
import java.util.Scanner;

public class TimeTableApp {
	public static void main(String[] args) {
		Lecture lecture[] = new Lecture[10];
		lecture[0] = new Lecture("MONDAY", 1, "OOP", "mr.park", "ITBT808", 20);
		lecture[1] = new Lecture("TUESDAY", 2, "security", "mr.park", "ITBT816", 20);
		lecture[2] = new Lecture("WEDNESDAY", 1, "Datastructure", "mr.park", "ITBT808", 25);
		lecture[3] = new Lecture("THURSDAY", 6, "Network", "mr.yang", "ITBT503", 20);
		lecture[4] = new Lecture("FRIDAY", 9, "computer architecture", "mr.han", "ITBT507", 20);
		lecture[5] = new Lecture("TUESDAY", 5, "Digital logic", "mr.kim", "ITBT401", 15);
		lecture[6] = new Lecture("WEDNESDAY", 2, "OS", "mr.yoon", "ITBT606", 15);
		lecture[7] = new Lecture("THURSDAY", 3, "C-language", "mr.choi", "ITBT503", 20);
		lecture[8] = new Lecture("FRIDAY", 6, "Python", "mr.han", "ITBT504", 15);
		lecture[9] = new Lecture("TUESDAY", 9, "Ski-Board", "mr.kang", "ITBT404", 5);

		Scanner keyboard = new Scanner(System.in);
		String[] weeks = { "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY" };
		Calendar cal = Calendar.getInstance();
		
		/* u can define variables */
		int enter; // command variable
		boolean endCoin = true; // loop variable
	
		System.out.println("학생수를 입력하세요.");
		int num = keyboard.nextInt();
		//keyboard.nextLine();
		Student student[] = new Student[num];
		for(int i=0;i<num;i++)
		{
			System.out.println(i+1 + " 학생의 이름을 입력하세요.");
			keyboard.nextLine();
			String Name = keyboard.nextLine();
			//keyboard.nextLine();
			System.out.println(i+1 + " 학생의 학번을 입력하세요.");
			int code = keyboard.nextInt();
			//keyboard.nextLine();
			student[i] = new Student(Name, code);
		}
		
		System.out.println("학생의 시간표를 입력하려면 1번을 누르세요");
		System.out.println("특정 과목을 수강하는 학생수를 출력하려면 2번을 누르세요");
		System.out.println("학생들의 시간표를 비교하려면 3번을 누르세요.");
		System.out.println("학생의 시간표를 지우려면 4번을 누르세요");
		System.out.println("시간표를 출력하려면 5번을 누르세요");
		System.out.println("해당 학생의 특정 날짜 시간표를 출력하려면 6번을 누르세요");
		System.out.println("프로그램을 종료하려면 7번을 누르세요");

		do {

			enter = keyboard.nextInt();
			//keyboard.nextLine();
			
			switch (enter) {
			case 1: //set schedule
				System.out.println("시간표를 입력할 학생의 학번을 입력하세요");
				int code = keyboard.nextInt();
				//keyboard.nextLine();
				System.out.println("다음 중 추가할 시간표의 번호를 입력하세요\n");
				showClass();
				int lecture_num = keyboard.nextInt();
				for(int i=0;i<num;i++)
				{
					if(student[i].getStudentCode() == code) // find student
					{
						//System.out.println(lecture_num);
						if(lecture_num<=0 || lecture_num>10) // can't find lecture data
						{
							System.out.println("존재하지 않는 강의를 선택하였습니다.");
							break;
						}
						else
						{
							student[i].setScheduleInformation(lecture[lecture_num-1]); // set schedule
							break;
						}
					}
					else if(student[i].getStudentCode() != code && i==num-1) // can't find student
					{
						System.out.println("입력하신 학번을 가진 학생은 존재하지 않습니다.");
					}
				}
			
				break;
				
			case 2://print lecture enrolled
				System.out.println("과목의 이름을 입력하세요");
				keyboard.nextLine();
				String str = keyboard.nextLine();
				//keyboard.nextLine();
				for(int i=0;i<10;i++)
				{
					if(lecture[i].getLectureName().equalsIgnoreCase(str.toString())) // find data lecture
					{
						System.out.println(str.toString()+" 과목을 수강하는 학생의 수는 " + lecture[i].getEnrolled());
						break;
					}
					else if(!lecture[i].getLectureName().equalsIgnoreCase(str.toString()) && i==9) // can't find data lecture
					{
						System.out.println(str.toString() + " 과목은 존재하지 않습니다.");
					}
				}
				break;
				
			case 3://compare two student timetable
				System.out.println("시간표를 비교할 첫번째 학생의 학번을 입력하세요");
				int first_code = keyboard.nextInt();
				//keyboard.nextLine();
				System.out.println("두번째 학생의 학번을 입력하세요");
				int second_code = keyboard.nextInt();
				//keyboard.nextLine();
				for(int i=0;i<num;i++)
				{
					if(student[i].getStudentCode() == first_code) // find first code
					{
						for(int j=i;j<num;j++)
						{
							if(student[j].getStudentCode() == second_code) // find second code
							{
								if(student[j].equals(student[i])) System.out.println("두 학생의 시간표는 같습니다.");
								else System.out.println("두 학생의 시간표는 다릅니다.");
								break;
							}
							else if(student[j].getStudentCode()!=second_code && j==num-1) // can't find second code student
							{
								System.out.println(second_code +" 학번을 가진 학생은 없습니다.");
							}
						}
						break;
					}
					else if(student[i].getStudentCode() == second_code) // find second code
					{
						for(int j=i;j<num;j++)
						{
							if(student[j].getStudentCode() == first_code) // find first code
							{
								if(student[j].equals(student[i])) System.out.println("두 학생의 시간표는 같습니다.");
								else System.out.println("두 학생의 시간표는 다릅니다.");
								break;
							}
							else if(student[j].getStudentCode()!=first_code && j==num-1) // can't find first code student
							{
								System.out.println(first_code +" 학번을 가진 학생은 없습니다.");
							}
						}
						break;
					}
					else if(student[i].getStudentCode() != first_code && student[i].getStudentCode() != second_code && i==num-1)// can't find first and second code
					{
						System.out.println(first_code +" 학번과 " + second_code + " 학번을 가진 학생은 없습니다.");
					}
				}
				break;
				
			case 4://delete schedule
				System.out.println("시간표를 삭제할 학생의 학번을 입력하세요");
				int del_code = keyboard.nextInt();
				//keyboard.nextLine();
				System.out.println("지울 시간표의 요일을 입력하세요");
				keyboard.nextLine();
				String del_day = keyboard.nextLine();
				//keyboard.nextLine();
				System.out.println("지울 시간표의 시간을 입력하세요");
				int del_time = keyboard.nextInt();
				//keyboard.nextLine();
				for(int i=0;i<num;i++)
				{
					if(student[i].getStudentCode() == del_code)//find student to delete schedule
					{
							student[i].deleteSchedule(del_day, del_time); // delete method
							System.out.println(student[i].showTimetable()); // print time table
							break;
					}
					else if(student[i].getStudentCode() != del_code && i==num-1) //can't find student code
					{
						System.out.println(del_code + " 학번을 가진 학생은 없습니다.");
					}
				}
				break;
				
			case 5://print timetable
				System.out.println("시간표를 출력할 학생의 학번을 입력하세요");
				int print_code = keyboard.nextInt();
				//keyboard.nextLine();
				for(int i=0;i<num;i++)
				{
					if(student[i].getStudentCode() == print_code) // find student
					{
						System.out.println(student[i].showTimetable());
						break;
					}
					else if(student[i].getStudentCode() != print_code && i==num-1) // can't find student
					{
						System.out.println(print_code + " 학번을 가진 학생은 없습니다.");
					}
				}
				break;
				
			case 6://print one day timetable
				System.out.println("출력할 학생의 학번을 입력하세요");
				int print_code_2 = keyboard.nextInt();
				//keyboard.nextLine();
				for(int i=0;i<num;i++)
				{
					if(student[i].getStudentCode()==print_code_2) // find student
					{
						cal = student[i].setInputDate(); // set cal object to set input date
						String print_day = weeks[cal.get(cal.DAY_OF_WEEK)-1]; 
						//System.out.println(print_day);
						System.out.println(student[i].oneDaySchedule(print_day)); // print one day time table
						break;
					}
					else if(student[i].getStudentCode() != print_code_2 && i==num-1) // can't find student
					{
						System.out.println(print_code_2 + " 학번을 가진 학생은 없습니다.");
					}
				}

				break;
			case 7://end of program
				endCoin = false;
				break;

			default://dafault - say again command
				System.out.println("Try again\n");
				System.out.println("학생의 시간표를 입력하려면 1번을 누르세요");
				System.out.println("특정 과목을 수강하는 학생수를 출력하려면 2번을 누르세요");
				System.out.println("학생들의 시간표를 비교하려면 3번을 누르세요.");
				System.out.println("학생의 시간표를 지우려면 4번을 누르세요");
				System.out.println("시간표를 출력하려면 5번을 누르세요");
				System.out.println("해당 학생의 특정 날짜 시간표를 출력하려면 6번을 누르세요");
				System.out.println("프로그램을 종료하려면 7번을 누르세요");
				break;
			}

		} while (endCoin);
	}

	private static void showClass() {
		System.out.println("(1) OOP - 월요일 - 1교시");
		System.out.println("(2) security - 화요일 - 2교시");
		System.out.println("(3) Datastructure - 수요일 - 1교시");
		System.out.println("(4) Network - 목요일 - 6교시");
		System.out.println("(5) computer architecture - 금요일 - 8교시");
		System.out.println("(6) Digital logic - 화요일 - 5교시");
		System.out.println("(7) OS - 수요일 - 2교시");
		System.out.println("(8) C-language - 목요일 - 3교시");
		System.out.println("(9) Python - 금요일 - 6교시");
		System.out.println("(10) Ski-Board - 화요일 - 9교시\n");
	}
}
