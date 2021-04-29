import java.util.*;
import java.math.BigInteger;

class uva10334{

public static void main(String[] q){

	Scanner scan=new Scanner(System.in);

	BigInteger[] F=new BigInteger[1001];
	F[0]=BigInteger.ONE;
	F[1]=new BigInteger("2");


	for(int I=2;I<=1000;I++){
		F[I]=F[I-1].add(F[I-2]);
		}
	int input;
	while(scan.hasNextInt())
	{
		input=scan.nextInt();
		System.out.println(F[input]);
		}

	}


}
