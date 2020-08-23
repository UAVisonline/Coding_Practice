package selfTest;

import java.util.Scanner;

public class GradeBook {
	private int numberOfStudents;
	private int numberOfQuizzes;
	
	private int [][] grade;
	
	private double[] studentAverage;
	private double[] quizAverage;

	public GradeBook()
	{
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("Enter the number of Students:");
		numberOfStudents = keyboard.nextInt();
		
		System.out.println("Enter the number of Quizzes:");
		numberOfQuizzes = keyboard.nextInt();
		
		grade = new int[numberOfStudents][numberOfQuizzes]; // declaration double-array grade
		for(int i=0;i<numberOfStudents;i++)
		{
			for(int j=0;j<numberOfQuizzes;j++)
			{
				System.out.println("Enter the score for student " + (i+1) + " on quiz " + (j+1));
				grade[i][j] = keyboard.nextInt(); // assign value
			}
		}
		
		fillStudentAverage();
		fillQuizAverage();
	}
	

	
	private void fillStudentAverage()
	{
		studentAverage = new double[numberOfStudents]; //declaration StudentAverage-array
		for(int i=0;i<numberOfStudents;i++)
		{
			double sum = 0; // make sum value
			for(int j=0;j<numberOfQuizzes;j++) sum+=grade[i][j];
			studentAverage[i] = sum/numberOfQuizzes; // assign StudentAverage value
			
		}
	}
	
	private void fillQuizAverage()
	{
		quizAverage = new double[numberOfQuizzes]; //declaration QuizAverage-array
		for(int i=0;i<numberOfQuizzes;i++)
		{
			double sum = 0; //make sum value
			for(int j=0;j<numberOfStudents;j++) sum+=grade[j][i];
			quizAverage[i] = sum/numberOfStudents; // assign QuizAverage value
			//System.out.println("check" + i);
		}
	}
	
	
	public void display()
	{
		for(int studentNumber =1; studentNumber <= numberOfStudents; studentNumber++)
		{
			System.out.print("Student " + studentNumber + " Quizzes: ");
			for(int quizNumber = 1;quizNumber <= numberOfQuizzes; quizNumber++)
				System.out.print(grade[studentNumber-1][quizNumber-1] + " ");
			System.out.println("Ave = " + studentAverage[studentNumber-1]);
		}
		
		System.out.println("Quiz average : ");
		
		for(int quizNumber = 1; quizNumber <= numberOfQuizzes;quizNumber++)
			System.out.print("Quiz "+quizNumber + " Ave = "+ quizAverage[quizNumber - 1] + " ");
		System.out.println();
	}
	
	
}