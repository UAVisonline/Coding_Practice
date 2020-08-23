package assignment03;

public class Candidate implements Comparable {

	private String name;
	private int numVotes = 0;
	private Vote[] votes;
	
	public Candidate(String name, int maxVotes) { // constructor
		//super();
		this.name = name; // set name
		votes = new Vote[maxVotes]; // assign Vote class array
		for(int i = 0;i<maxVotes;i++)
		{
			votes[i] = null; // all vote class is NULL
		}
	}
	
	public String toString() {
		String str = "";
		str += "Name: " + this.name + "\n";
		str += "Total Votes: " + numVotes + "\n";
		return str;
	}
	
	public int return_Votes()
	{
		return numVotes;
	}
	
	public int toRegionString(int regionNum) { 
		int vote_num = 0;
		
		for(int i = 0;i<numVotes;i++)
		{
			if(votes[i] != null)
			{
				if(votes[i].regionNum == regionNum) vote_num++; // if regionNum same as votes_region, vote++
			}
		}
		
		return vote_num;
	}
	
	public void callAddVotes(int regionNum) throws InterruptedException {
		Vote vote = new Vote(regionNum);
		vote.addVote(regionNum);
	}
	
	@Override
	public int compareTo(Object obj) {
		int obj_votes = ((Candidate)obj).return_Votes(); // return object vote
		return obj_votes - this.numVotes; // ascending order comparison
	}
	
	private class Vote { // Inner class Vote

		private int regionNum; // region Number
		
		public Vote(int regionNum) {
			this.regionNum = regionNum;
		}
		
		public synchronized void addVote(int regionNum) throws InterruptedException
		{
			if(votes.length <= numVotes)
			{
				System.out.println("Vote array is full");
				wait(); // if votes are full, then wait
			}
			votes[numVotes++] = new Vote(regionNum); // vote array assign new Vote class
			notifyAll();
		}
	}
}
