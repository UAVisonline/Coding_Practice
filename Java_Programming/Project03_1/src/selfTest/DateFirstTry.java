package selfTest;

public class DateFirstTry {

	public String month;
	public int day;
	
	public void makeItNewYears() //신년 날짜 설정 method
	{
		month = "January";
		day = 1;
	}
	
	public String yellIfNewYear() //신년 확인 method
	{
		if(month.equals("January")== true && day==1) return "Happy New Year!";
		else return "Not New Year's Day.";
	}
	
}
