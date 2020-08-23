package selfTest;

import java.util.Arrays;

public class MyCustom implements MyInterface {
	private Integer move_type = 0;
	private Boolean isAttack = false;
	
	public void move(String key) {
		if(key.equalsIgnoreCase("w")) move_type = 1;
		else if(key.equalsIgnoreCase("s")) move_type = 2;
		else if(key.equalsIgnoreCase("a")) move_type = 3;
		else if(key.equalsIgnoreCase("d")) move_type = 4;
		else move_type=5;
	}
	public void attack(String key) {
		if(key.equalsIgnoreCase("Spacebar")) isAttack = true;
		else isAttack = false;
	}
	public void sortItem(Item[] itemList) {
		Arrays.sort(itemList);
	}
	public Integer getMoveType() {
		return this.move_type;
	}
	public Boolean getIsAttack() {
		return this.isAttack;
	}
}
