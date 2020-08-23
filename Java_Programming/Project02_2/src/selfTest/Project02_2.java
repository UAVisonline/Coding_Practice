package selfTest;

public class Project02_2 {

	public static void main(String[] args) {
		for(int intVal1 = 1;intVal1<=5;intVal1++)
		{
			for(int intVal2=5;intVal2>=1;intVal2--) System.out.println( intVal1 +" multiplied by " + intVal2 + " = " + intVal1*intVal2);
			//nested loop intVal1*intVal2(intVal1 increase, intVal2 decrease)
		}	
	}
}
