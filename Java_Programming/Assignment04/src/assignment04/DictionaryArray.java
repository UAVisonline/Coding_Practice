package assignment04;

import java.util.ArrayList;
import java.util.Iterator;

public class DictionaryArray implements Dictionary{ // use interface Dictionary

	private ArrayList<WordDefinitionPair> DicList; // ArrayList <Word> = Dictionary
	
	public DictionaryArray() // default constructor
	{
		DicList = new ArrayList<WordDefinitionPair>();
	}
	
	public ArrayList<WordDefinitionPair> Return_DicList() //Return_Dictionary
	{
		ArrayList<WordDefinitionPair> temp = new ArrayList<WordDefinitionPair>(); // new ArrayList
		for(int i=0;i<DicList.size();i++)
		{
			temp.add(DicList.get(i)); //insert word in new ArrayList
		}
		return temp; // return new ArrayList
	}
	
	public boolean isEmpty() //Empty Dictionary
	{
		if(DicList.isEmpty()) return true;
		else return false;
	}
	
	public void insertEntry(String word, String definition) throws AlreadyExistInDicException //insert word in Dictionary
	{
		if(!DicList.isEmpty()) // Not Empty Dictionary
		{
			for(int i = 0;i<DicList.size();i++) //Find same word
			{
				String str = DicList.get(i).Return_Word();
				if(str.toString().equals(word.toString())) // if same word
				{
					throw new AlreadyExistInDicException(); //throw Exception about AlreadyExistInDictionary
				}
			}
		}
		WordDefinitionPair temp = new WordDefinitionPair(word,definition); // new Class assign
		DicList.add(temp); // add new Class object in Dictionary
	}
	
	public void getDefinition(String word) throws EmptyException, NotInDicException //Find word and print definition
	{
		if(DicList.isEmpty()) throw new EmptyException(); // Empty dictionary so throw EmptyException
		for(int i = 0;i<DicList.size();i++)
		{
			String str = DicList.get(i).Return_Word();
			if(str.toString().equals(word.toString())) //Find word
			{
				System.out.print(word.toString() + " mean : ");
				System.out.println(DicList.get(i).Return_Definition().toString()); //Print Definition
				return;
			}
		}
		
		throw new NotInDicException(); // if can't find, throw NotinDic Exception
	}
	
	public void removeWord(String word) throws EmptyException, NotInDicException //Remove Word in Dictionary
	{
		if(DicList.isEmpty()) throw new EmptyException(); // Empty Dictionary
		for(int i = 0;i<DicList.size();i++)
		{
			String str = DicList.get(i).Return_Word();
			if(str.toString().equals(word.toString())) //Find word
			{
				DicList.remove(i); // Remove word index of i in ArrayList
				return;
			}
		}
		throw new NotInDicException(); // if can't find, throw NotinDic Exception
	}
	
	public void printWords() throws EmptyException
	{
		if(DicList.isEmpty()) throw new EmptyException(); 
		for(int i = 0;i<DicList.size();i++)
		{
			System.out.println(i+1 + ". " + DicList.get(i).Return_Word()); // Print word
		}
		
	}
	
	public void printAll() throws EmptyException
	{
		if(DicList.isEmpty()) throw new EmptyException();
		for(int i = 0;i<DicList.size();i++)
		{
			System.out.println("*******************************");
			System.out.println("Word : " + DicList.get(i).Return_Word()); // Print word
			System.out.println("Definition : " + DicList.get(i).Return_Definition()); // Print definition
		}
		
	}
	
}
