package assignment04;

public class WordDefinitionPair {

	private String word;
	private String definition;
	
	public WordDefinitionPair(String word, String definition) //default constructor
	{
		this.word = word;
		this.definition = definition;
	}
	
	public String Return_Word()
	{
		return this.word.toString();
	}
	
	public String Return_Definition()
	{
		return this.definition.toString();
	}
	
	public void Set_Word(String word)
	{
		this.word = word;
	}
	
	public void Set_Definition(String definition)
	{
		this.definition = definition;
	}
}
