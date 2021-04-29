import java.util.*;
import java.math.BigInteger;

class uva11448{

public static void main(String[] q){

	Scanner scan=new Scanner(System.in);

	int test=scan.nextInt();

	while(test-- >0){

		BigInteger A=scan.nextBigInteger();
		BigInteger B=scan.nextBigInteger();
		System.out.println(A.subtract(B));

		}
	}


}
