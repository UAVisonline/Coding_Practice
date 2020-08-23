package selfTest;

public class TooMuchStuffException extends Exception {

	private int inputNumber;
	
	public TooMuchStuffException(String str) {
		super(str);
	}
	
	public TooMuchStuffException() {
		super("Too much stuff!");
	}
	
	public TooMuchStuffException(int num) {
		super("Too much stuff!");
		inputNumber = num;
	}
	
	public int getNumber() {
		return inputNumber;
	}
	
}
