import java.util.*;
import java.math.BigInteger;

class Main{
	public static void main(String[] q){
		Scanner scan=new Scanner(System.in);
		int test,N=1;
		BigInteger B,T,F;

		while(true){
			test=scan.nextInt();
			if(test==0)
				break;
			B=scan.nextBigInteger();
			T=BigInteger.ZERO;
			for(int I=0;I<test;I++){
				F=scan.nextBigInteger();
				T=T.add(F);
				}
			System.out.println("Bill #"+N+" costs "+T+": each friend should pay "+T.divide(B)+"\n");
			N++;
			}
		}
};