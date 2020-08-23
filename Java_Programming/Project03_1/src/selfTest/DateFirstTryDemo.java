package selfTest;

public class DateFirstTryDemo {

	public static void main(String[] args) {
		
		//date1 설정, 날짜는 오늘 날짜로 설정
		DateFirstTry date1 = new DateFirstTry();
		date1.month = "April";
		date1.day = 9;
		
		//date2 설정, 날짜는 생일로 설정후 makeItNewYears method 호출
		DateFirstTry date2 = new DateFirstTry();
		date2.month = "December";
		date2.day = 17;
		date2.makeItNewYears();
		
		//결과값 출력
		System.out.println("date1: " + date1.yellIfNewYear());
		System.out.println("date2: " + date2.yellIfNewYear());
		
	}

}
