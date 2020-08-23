package Assignment02;

import java.util.Scanner;

public class PriceListApp {

	public static void main(String[] args)
	{
		int input;
		Scanner keyboard = new Scanner(System.in);
		PriceList pricelist = new PriceList(); 
		int list_width = 0; // variable about position vertical
		boolean program = true; // program loop variable
		
		while(program)
		{
			System.out.println("==========Main Menu==========");
			System.out.println("(1) Add a oil to price list");
			System.out.println("(2) View Region Information");
			System.out.println("(3) Print the entire price list");
			System.out.println("(4) Exit the program");
			System.out.println("=============================");
			
			System.out.print("choose a menu : ");
			input = keyboard.nextInt(); // command
			switch(input)
			{
			case 1:
				try 
				{
					if(pricelist.Get_vertical() <= list_width) // if list_position is bigger than real array width
					{
						throw new FullArrayException(); // throw FullArrayException
					}
				}
				catch(FullArrayException e) // catch exception
				{
					e.get_Full(); // print error
					int expand_num = keyboard.nextInt(); 
					pricelist.extendList(expand_num); //expand list
				}
				
				System.out.print("company : ");
				keyboard.nextLine();
				String company_name_1 =keyboard.nextLine();
				System.out.print("supply price : ");
				int supply_price_1 = keyboard.nextInt();
				Gasoline gas = new Gasoline(company_name_1,supply_price_1);
				pricelist.setPriceList(list_width, 0, gas);
				System.out.println("gasoline added\n");
				//gasoline oil added
				
				System.out.print("company : ");
				keyboard.nextLine();
				String company_name_2 =keyboard.nextLine();
				System.out.print("supply price : ");
				int supply_price_2 = keyboard.nextInt();
				Diesel dis = new Diesel(company_name_2,supply_price_2);
				pricelist.setPriceList(list_width, 1, dis);
				System.out.println("diesel added\n");
				//diesel oil added
				
				list_width++; // position up
				break;
			case 2:
				System.out.print("region number to view : ");
				int number = keyboard.nextInt(); // number of where you want to see the case of region
				System.out.println(pricelist.getRegionInfo(number)); // print it
				break;
			case 3:
				pricelist.priceList(); // all consumer price print method
				break;
			case 4: // program end
				program = false;
				System.out.println("Exit Application");
				break;
			default: // insert 1~4
				System.out.println("insert 1~4");
				break;
			}
		}
		
	}
	
}
