import java.util.*;
import java.math.BigInteger;



class uva1226{

public static void main(String[] q){

	Scanner scan=new Scanner(System.in);
	int test=scan.nextInt();
	BigInteger A,B;
	while(test-- >0)
	{
		A=scan.nextBigInteger();
		B=scan.nextBigInteger();
		System.out.println(B.mod(A));
		}

	}


}
