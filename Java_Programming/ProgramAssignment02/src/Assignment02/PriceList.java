package Assignment02;

import java.util.Scanner;

public class PriceList {

	private Oil[][] pricelist;
	private int vertical;
	
	PriceList() // default constructor
	{
		vertical = 2; // set 2 vertical
		pricelist = new Oil[2][2];
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				pricelist[i][j] = null; // initialize pricelist object to null
			}
		}
	}
	
	public int Get_vertical() //getter vertical variable
	{
		return vertical;
	}
	
	public void setPriceList(int i, int j, Oil oil) // set price list method
	{
		
		if(j%2==0) // gasoline case
		{
			//Gasoline gas = (Gasoline)oil;
			
			pricelist[i][j] = oil; // shallow copy : pricelist initialize oil object(gasoline)
			
			//pricelist[i][j] = new Gasoline(oil.Get_name(),(int)oil.getOilPrice());
			//System.out.println((int)oil.getOilPrice());
		}
		else // diesel case
		{
			//Diesel dis = (Diesel)oil;
			
			pricelist[i][j] = oil; // shallow copy : pricelist initialize oil object(diesel)
			
			//pricelist[i][j] = new Diesel(oil.Get_name(),(int)oil.getOilPrice());
			//System.out.println(oil.getOilPrice() + 50000);
		}
		
		//System.out.println(pricelist[i][j].Get_comsumerPrice());
	}
	
	public void extendList(int expand) // extend array_length
	{
		vertical += expand; // vertical change
		
		Oil[][] pricelist_replace = new Oil[vertical][2]; // new Oil[][] object initialize
		for(int i=0;i<vertical;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(i<vertical-expand)
				{
					pricelist_replace[i][j] = pricelist[i][j]; // copy to object
				}
				else
				{
					pricelist_replace[i][j] = null; // empty case : null initialize
				}
			}
		}
		
		pricelist = new Oil[vertical][2]; // change pricelist array
		for(int i=0;i<vertical;i++)
		{
			for(int j=0;j<2;j++)
			{
				pricelist[i][j] = pricelist_replace[i][j]; // copy from new oil[][] to pricelist
			}
		}
	}
	
	public String getRegionInfo(int i) // get information some part method
	{
		String str = "";
		if(i>vertical || i<=0) // i is not in range in length
		{
			str = "out of index";
		}
		else if(pricelist[i-1][0] == null || pricelist[i-1][1] == null) // empty case
		{
			str = "out of index";
		}
		else
		{
			str += pricelist[i-1][0].toString() + "\n"; // assign value for print information
			str += pricelist[i-1][1].toString();
		}
		return str; // return string
	}
	
	public void priceList() // print all information method
	{
		if(pricelist[0][0] == null)
		{
			System.out.println("No data inserted in table"); // no data in array
		}
		else
		{
			System.out.print("                 Gasoline        Diesel\n");
			System.out.println("=============================================");
			for(int i=0;i<vertical;i++)
			{
				if(pricelist[i][0]!=null)
				{
					System.out.println(String.format("Region #" + (i+1) + "%15.2f" +   "%15.2f",pricelist[i][0].getOilPrice(),pricelist[i][1].getOilPrice()));
					//print information about consumer price
				}
				else
				{
					break;
				}
			}
		}
	}
}
