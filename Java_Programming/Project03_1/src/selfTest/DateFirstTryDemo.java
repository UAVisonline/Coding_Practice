package selfTest;

public class DateFirstTryDemo {

	public static void main(String[] args) {
		
		//date1 ����, ��¥�� ���� ��¥�� ����
		DateFirstTry date1 = new DateFirstTry();
		date1.month = "April";
		date1.day = 9;
		
		//date2 ����, ��¥�� ���Ϸ� ������ makeItNewYears method ȣ��
		DateFirstTry date2 = new DateFirstTry();
		date2.month = "December";
		date2.day = 17;
		date2.makeItNewYears();
		
		//����� ���
		System.out.println("date1: " + date1.yellIfNewYear());
		System.out.println("date2: " + date2.yellIfNewYear());
		
	}

}
