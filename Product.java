import java.util.*;
import java.math.BigInteger;
class Product{
	public static void main(String[] q){
	Scanner scan=new Scanner(System.in);
	BigInteger A,B;
	while(scan.hasNextBigInteger()){
		A=scan.nextBigInteger();
		B=scan.nextBigInteger();
		A=A.multiply(B);
	System.out.println(A);
	}

	}


};