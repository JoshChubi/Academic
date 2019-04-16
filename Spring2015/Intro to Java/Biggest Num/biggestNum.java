/*CS 552 Josh Ortiz */
import java.util.Scanner;

class biggestNum
{
		public static void main(String[] args)
		{
			float n1, n2, n3, temp;
			
			System.out.println("Please enter 3 sides\n");
			
			Scanner scanNumber = new Scanner(System.in);
			
			n1=scanNumber.nextFloat();
			n2=scanNumber.nextFloat();
			n3=scanNumber.nextFloat();
			
			if(n1>n2)
			{
				temp=n1;
				n1=n2;
				n2=temp;
			}else if(n2>n3)
				{
					temp=n2;
					n2=n3;
					n3=temp;
				}else if(n1>n2)
					{
						temp = n1;
						n1=n2;
						n2=temp;
					}
			
			System.out.println(n1 +"\n"+n2+"\n"+n3);
			System.out.println("\nBiggest number you input is: "+n3);
		}
}
