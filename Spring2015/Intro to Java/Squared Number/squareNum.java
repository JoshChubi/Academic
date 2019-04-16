/*CS 552 Josh Ortiz*/
import java.util.Scanner;

class squareNum
{
		public static void main (String[] args)
		{
			int number, temp, square;
			
			Scanner scanNumber = new Scanner(System.in);
			
			System.out.println("Please input a number between 1000=9999\n");
			
			number = scanNumber.nextInt();
			
			temp=number%1000;
			temp/=10;
			
			square=number * number;
			
			System.out.println("Square is: "+square+"\n");
			
			System.out.println("The middle number is:"+temp+"\n");

		}
}
