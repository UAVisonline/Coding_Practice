package selfTest;

public class DateFirstTry {

	public String month;
	public int day;
	
	public void makeItNewYears() //�ų� ��¥ ���� method
	{
		month = "January";
		day = 1;
	}
	
	public String yellIfNewYear() //�ų� Ȯ�� method
	{
		if(month.equals("January")== true && day==1) return "Happy New Year!";
		else return "Not New Year's Day.";
	}
	
}
