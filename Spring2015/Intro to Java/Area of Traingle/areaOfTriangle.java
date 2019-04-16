/*CS 552 Josh Ortiz*/
import java.util.Scanner;

class areaOfTriangle
{
	public static void main(String[] args)
	{
		float base, height, area;
		
		Scanner triangleScan = new Scanner(System.in);
		
		System.out.println("Please enter the base in linear feet\n");
		base = triangleScan.nextFloat();
		
		System.out.println("Please enter the hight in linear feet\n");
		height = triangleScan.nextFloat();
		
		area = base*height/2;
		
		System.out.println("The area is: "+area+" Square ft");
	}
}
