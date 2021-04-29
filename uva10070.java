import java.util.*;
import java.math.BigInteger;


class year{

	boolean Mod(BigInteger A,BigInteger B){

		BigInteger C=A.mod(B);

			if((""+C).compareTo("0")==0)
				return true;
		return false;

		}



	boolean leapYear(BigInteger year){

		if(Mod(year,new BigInteger("400"))==true )
			return true;
		if(Mod(year,new BigInteger("100"))==true )
			return false;
		if(Mod(year,new BigInteger("4"))==true)
			return true;
		return false;
		}

	boolean hakuluku(BigInteger year){

		if(Mod(year,new BigInteger("15"))==true)
			return true;
		return false;
		}

	boolean balukulu(BigInteger year){

		if(Mod(year,new BigInteger("55"))==true)
			return true;
		return false;
		}
	}





class uva10070{

public static void main(String[] q){

	Scanner scan = new Scanner(System.in);
	year fastival=new year(); //Dnt afraid...year is a class and festtival is a object of this class.
	BigInteger Y;

	int T=0;

	boolean b,ordinary;
		while(scan.hasNextBigInteger()){

			b=false;
			ordinary=true;
			
			if(T>0)
				System.out.print("\n");
			
			Y=scan.nextBigInteger();

			if(fastival.leapYear(Y)==true){
				System.out.println("This is leap year.");
				b=true;
				ordinary=false;
			}

			if(fastival.hakuluku(Y)==true){
				System.out.println("This is huluculu festival year.");
				ordinary=false;
			}

			if(b==true && fastival.balukulu(Y)==true ){
				System.out.println("This is bulukulu festival year.");
				ordinary=false;
			}

			if(ordinary==true)
				System.out.println("This is an ordinary year.");



		T++;
		}


	}


}
