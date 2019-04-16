/*CS 552 Josh Ortiz*/
import java.util.Scanner;

class onee
{
	public static void main(String[] args)
	{
		float base, hight, area;
		
		Scanner triangleScan = new Scanner(System.in);
		
		System.out.println("Please enter the base in liner feet\n");
		base = triangleScan.nextFloat();
		
		System.out.println("Please enter the hight in liner feet\n");
		hight = triangleScan.nextFloat();
		
		area = base*hight/2;
		
		System.out.println("The area is: "+area+" Square ft");
	}
}
