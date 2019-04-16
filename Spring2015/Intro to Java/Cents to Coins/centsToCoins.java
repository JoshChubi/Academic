/*CS 552 Josh Ortiz*/
import java.util.Scanner;

class centsToCoins
{
	public static void main(String[] args)
	{
		int cents, quarter, dime, nickel, penny;
		
		Scanner centScan = new Scanner(System.in);
		
		System.out.println("Please enter total number of cents: \n");
		cents = centScan.nextInt();
		
		quarter = cents/25;
		dime = (cents%25) / 10;
		nickel = ((cents % 25 )%10) /5;
		penny = ((cents % 25) % 10) % 5;
		
		System.out.println("Number of cents: " + cents + "\n");
		System.out.println("Number of quarters: " + quarter + "\n");
		System.out.println("Number of dime: " + dime +"\n");
		System.out.println("Number of nickel:" +nickel +"\n");
		System.out.println("Number of penny: " + penny);
	}
}
