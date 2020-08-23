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
	
		System.out.println("�л����� �Է��ϼ���.");
		int num = keyboard.nextInt();
		//keyboard.nextLine();
		Student student[] = new Student[num];
		for(int i=0;i<num;i++)
		{
			System.out.println(i+1 + " �л��� �̸��� �Է��ϼ���.");
			keyboard.nextLine();
			String Name = keyboard.nextLine();
			//keyboard.nextLine();
			System.out.println(i+1 + " �л��� �й��� �Է��ϼ���.");
			int code = keyboard.nextInt();
			//keyboard.nextLine();
			student[i] = new Student(Name, code);
		}
		
		System.out.println("�л��� �ð�ǥ�� �Է��Ϸ��� 1���� ��������");
		System.out.println("Ư�� ������ �����ϴ� �л����� ����Ϸ��� 2���� ��������");
		System.out.println("�л����� �ð�ǥ�� ���Ϸ��� 3���� ��������.");
		System.out.println("�л��� �ð�ǥ�� ������� 4���� ��������");
		System.out.println("�ð�ǥ�� ����Ϸ��� 5���� ��������");
		System.out.println("�ش� �л��� Ư�� ��¥ �ð�ǥ�� ����Ϸ��� 6���� ��������");
		System.out.println("���α׷��� �����Ϸ��� 7���� ��������");

		do {

			enter = keyboard.nextInt();
			//keyboard.nextLine();
			
			switch (enter) {
			case 1: //set schedule
				System.out.println("�ð�ǥ�� �Է��� �л��� �й��� �Է��ϼ���");
				int code = keyboard.nextInt();
				//keyboard.nextLine();
				System.out.println("���� �� �߰��� �ð�ǥ�� ��ȣ�� �Է��ϼ���\n");
				showClass();
				int lecture_num = keyboard.nextInt();
				for(int i=0;i<num;i++)
				{
					if(student[i].getStudentCode() == code) // find student
					{
						//System.out.println(lecture_num);
						if(lecture_num<=0 || lecture_num>10) // can't find lecture data
						{
							System.out.println("�������� �ʴ� ���Ǹ� �����Ͽ����ϴ�.");
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
						System.out.println("�Է��Ͻ� �й��� ���� �л��� �������� �ʽ��ϴ�.");
					}
				}
			
				break;
				
			case 2://print lecture enrolled
				System.out.println("������ �̸��� �Է��ϼ���");
				keyboard.nextLine();
				String str = keyboard.nextLine();
				//keyboard.nextLine();
				for(int i=0;i<10;i++)
				{
					if(lecture[i].getLectureName().equalsIgnoreCase(str.toString())) // find data lecture
					{
						System.out.println(str.toString()+" ������ �����ϴ� �л��� ���� " + lecture[i].getEnrolled());
						break;
					}
					else if(!lecture[i].getLectureName().equalsIgnoreCase(str.toString()) && i==9) // can't find data lecture
					{
						System.out.println(str.toString() + " ������ �������� �ʽ��ϴ�.");
					}
				}
				break;
				
			case 3://compare two student timetable
				System.out.println("�ð�ǥ�� ���� ù��° �л��� �й��� �Է��ϼ���");
				int first_code = keyboard.nextInt();
				//keyboard.nextLine();
				System.out.println("�ι�° �л��� �й��� �Է��ϼ���");
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
								if(student[j].equals(student[i])) System.out.println("�� �л��� �ð�ǥ�� �����ϴ�.");
								else System.out.println("�� �л��� �ð�ǥ�� �ٸ��ϴ�.");
								break;
							}
							else if(student[j].getStudentCode()!=second_code && j==num-1) // can't find second code student
							{
								System.out.println(second_code +" �й��� ���� �л��� �����ϴ�.");
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
								if(student[j].equals(student[i])) System.out.println("�� �л��� �ð�ǥ�� �����ϴ�.");
								else System.out.println("�� �л��� �ð�ǥ�� �ٸ��ϴ�.");
								break;
							}
							else if(student[j].getStudentCode()!=first_code && j==num-1) // can't find first code student
							{
								System.out.println(first_code +" �й��� ���� �л��� �����ϴ�.");
							}
						}
						break;
					}
					else if(student[i].getStudentCode() != first_code && student[i].getStudentCode() != second_code && i==num-1)// can't find first and second code
					{
						System.out.println(first_code +" �й��� " + second_code + " �й��� ���� �л��� �����ϴ�.");
					}
				}
				break;
				
			case 4://delete schedule
				System.out.println("�ð�ǥ�� ������ �л��� �й��� �Է��ϼ���");
				int del_code = keyboard.nextInt();
				//keyboard.nextLine();
				System.out.println("���� �ð�ǥ�� ������ �Է��ϼ���");
				keyboard.nextLine();
				String del_day = keyboard.nextLine();
				//keyboard.nextLine();
				System.out.println("���� �ð�ǥ�� �ð��� �Է��ϼ���");
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
						System.out.println(del_code + " �й��� ���� �л��� �����ϴ�.");
					}
				}
				break;
				
			case 5://print timetable
				System.out.println("�ð�ǥ�� ����� �л��� �й��� �Է��ϼ���");
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
						System.out.println(print_code + " �й��� ���� �л��� �����ϴ�.");
					}
				}
				break;
				
			case 6://print one day timetable
				System.out.println("����� �л��� �й��� �Է��ϼ���");
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
						System.out.println(print_code_2 + " �й��� ���� �л��� �����ϴ�.");
					}
				}

				break;
			case 7://end of program
				endCoin = false;
				break;

			default://dafault - say again command
				System.out.println("Try again\n");
				System.out.println("�л��� �ð�ǥ�� �Է��Ϸ��� 1���� ��������");
				System.out.println("Ư�� ������ �����ϴ� �л����� ����Ϸ��� 2���� ��������");
				System.out.println("�л����� �ð�ǥ�� ���Ϸ��� 3���� ��������.");
				System.out.println("�л��� �ð�ǥ�� ������� 4���� ��������");
				System.out.println("�ð�ǥ�� ����Ϸ��� 5���� ��������");
				System.out.println("�ش� �л��� Ư�� ��¥ �ð�ǥ�� ����Ϸ��� 6���� ��������");
				System.out.println("���α׷��� �����Ϸ��� 7���� ��������");
				break;
			}

		} while (endCoin);
	}

	private static void showClass() {
		System.out.println("(1) OOP - ������ - 1����");
		System.out.println("(2) security - ȭ���� - 2����");
		System.out.println("(3) Datastructure - ������ - 1����");
		System.out.println("(4) Network - ����� - 6����");
		System.out.println("(5) computer architecture - �ݿ��� - 8����");
		System.out.println("(6) Digital logic - ȭ���� - 5����");
		System.out.println("(7) OS - ������ - 2����");
		System.out.println("(8) C-language - ����� - 3����");
		System.out.println("(9) Python - �ݿ��� - 6����");
		System.out.println("(10) Ski-Board - ȭ���� - 9����\n");
	}
}
