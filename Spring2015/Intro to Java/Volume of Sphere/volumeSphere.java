/*CS 552 Josh Ortiz*/

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;

class volumeSphere{
	public static void main (String[] args) throws java.lang.Exception
	{
		final double PI = 3.141516;
		double volume, radius;
		Scanner scan=new Scanner(System.in);
		
		System.out.println("Enter the radius Please: ");
		
		radius = scan.nextDouble();
		
		volume = 4/3.*PI*radius*radius*radius;
		
		System.out.println("Volume is: "+volume);
		
	}
}
