package assignment03;

public class Region extends Thread{

	private String regionName;			// The name of the region
	private int regionNum;			// The number of the region
	private int population;			// The population of the region
	private Candidate[] candidates;	// An array of the candidates of the election
	
	public Region(String regionName, int regionNum, int population, Candidate[] parameter_candidates) { //constructor
		//super();
		this.regionName = regionName;
		this.regionNum = regionNum;
		this.population = population;
		candidates = new Candidate[parameter_candidates.length]; // set length of candidate class array
		for(int i = 0;i<candidates.length;i++)
		{
			candidates[i] = parameter_candidates[i]; // assign candidate class array to parameter class array
		}
	}
	
	public String getRegionName() {
		return this.regionName.toString();
	}
	
	public int getRegionNum() {
		return this.regionNum;
	}
	
	public void generateVotes() throws InterruptedException {
		for(int i =0;i<population;i++) // Region population loop
		{
			int random = (int)(Math.random()*candidates.length); 
			candidates[random].callAddVotes(this.regionNum); //random vote
		}
	}
	
	public void run() {
		try
		{
			generateVotes(); 
		}
		catch (InterruptedException e)
		{
			e.printStackTrace();
		}
	}
}
