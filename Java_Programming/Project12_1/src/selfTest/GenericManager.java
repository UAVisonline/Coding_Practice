package selfTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class GenericManager<T extends Comparable> {
	
	private ArrayList<T> cList;

	public GenericManager() {
		cList = new ArrayList<T>();
	}
	
	public void add(T a) {
		cList.add(a);
	}
	
	public void sort() {
		Collections.sort(cList);
	}
	
	public String find(T a) {
		String str = "";
		for(Iterator<T>iter = cList.iterator();iter.hasNext();)
		{
			T temp = iter.next();
			if(temp.equals(a))
			{
				str += temp.toString();
			}
		}
		return str;
	}
	
	public String toString() {
		String str = "";
		for(Iterator<T>iter = cList.iterator();iter.hasNext();)
		{
			T temp = iter.next();
			str += temp.toString();
		}
		return str;
	}
}
