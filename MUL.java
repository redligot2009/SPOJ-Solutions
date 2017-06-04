/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner myScanner = new Scanner(System.in);
		int times = myScanner.nextInt();
		while(times > 0)
		{
			BigInteger l1, l2;
			l1 = myScanner.nextBigInteger();
			l2 = myScanner.nextBigInteger();
			BigInteger product = l1.multiply(l2);
			System.out.println(product);
			times --;
		}
	}
}