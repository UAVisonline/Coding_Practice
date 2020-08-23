package selfTest;

import java.util.Scanner;

public class TestScores {
	public static final int MAX_NUMBER_SCORES = 10; //max size of array

	public static void main(String[] args) {
		
		double[] scores = new double[MAX_NUMBER_SCORES];
		int counting = 0; 
		
		System.out.println("This program reads test scores and shows");
		System.out.println("how much each differs from the average.");
		System.out.println("Enter test scores:");
		
		counting = fillArray(scores);
		showDifference(scores, counting);
		
	}

	public static int fillArray(double[] score_list)
	{
		System.out.println("Mark the end of the list with a negative number.");	
		Scanner scan = new Scanner(System.in); // scanner class declaration
		int count = 0; // return value
		for(int i=0;i<MAX_NUMBER_SCORES;i++)
		{
			score_list[i] = scan.nextDouble(); //input value
			if(score_list[i]<0) break; // minus value
			else count++; 
		}
		return count;
	}
	
	public static void showDifference(double[] score_list,int count)
	{
		double average = computeAverage(score_list, count); // get Average
		
		System.out.println("Average of the scores = " + average);
		System.out.println("The scores are: ");
		
		for(int i=0;i<count;i++) System.out.println(score_list[i] + " differs from average by " + (score_list[i] - average));
	}
	
	public static double computeAverage(double[] score_list, int count)
	{	
		double sum = 0; 
		for(int i=0;i<count;i++) sum+=score_list[i]; //sum of list && if use length, not count value, sum += empty value
		return sum/count; //return average
	}
}
