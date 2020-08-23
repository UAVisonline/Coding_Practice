package assignment04;

public interface Dictionary { // Dictionary Interface
	public boolean isEmpty(); //Empty dictionary
	public void insertEntry(String word, String definition) throws AlreadyExistInDicException; //insert word in dictionary
	public void getDefinition(String word) throws EmptyException, NotInDicException; // find word and print definition
	public void removeWord(String word) throws EmptyException, NotInDicException; // Remove specific word in dictionary
	public void printWords() throws EmptyException; // print word list
	public void printAll() throws EmptyException; // print All word and its definition
}
