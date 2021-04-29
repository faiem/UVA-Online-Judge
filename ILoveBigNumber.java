import java.util.*;
import java.math.BigInteger;
class Main{

	public static void main(String[] q){

		Scanner scan=new Scanner(System.in);
		String S;
		int[] sum=new int[1001];
		BigInteger[] F=new BigInteger[1001];
		F[0]=BigInteger.ONE;
		sum[0]=1;
		for(int I=1;I<=1000;I++){
			sum[I]=0;
			F[I]=F[I-1].multiply(new BigInteger(""+I));
			S=new String(""+F[I]);
			for(int J=0;J<S.length();J++){
				sum[I]+=S.charAt(J)-48;
				}
			}

		while(scan.hasNextInt())
		{
			int input=scan.nextInt();
			System.out.println(sum[input]);
			}


		}

	}
