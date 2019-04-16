/*CS 552 Josh Ortiz*/

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;

class eggCarton
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int egg, cartoon;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter number of eggs please\n");
		egg = scan.nextInt();
		cartoon = egg/12;
		
		System.out.println("Total number of cartoons needed is: "+ cartoon);
	}
}
