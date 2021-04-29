import java.util.*;
import java.math.BigInteger;

class FindBigIntegerRoot{

	 BigInteger bigsqrt(BigInteger x)
	{
	           BigInteger x_0,x_1=x,div=new BigInteger("2");
	            do
	            {
	                x_0=x_1;
	                x_1=x_0.add(x.divide(x_0)).divide(div);

	            }while(x_0.compareTo(x_1)!=0);
	return x_1;
	}

	}



class 10023{

public static void main(String[] q){

	Scanner scan=new Scanner(System.in);
	FindBigIntegerRoot r=new FindBigIntegerRoot();
	int test=scan.nextInt();
	int T=1;

	while(test-- >0)
	{
		if(T>1)
		System.out.println();
		BigInteger input=scan.nextBigInteger();
		System.out.println(r.bigsqrt(input));
		}

	}


}
