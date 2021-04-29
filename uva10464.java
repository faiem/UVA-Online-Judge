import java.math.BigDecimal;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    BigDecimal decimalA, decimalB;
	Scanner scan=new Scanner(System.in);
	int test=scan.nextInt();
	while(test-- >0){
    	decimalA=scan.nextBigDecimal();
    	decimalB=scan.nextBigDecimal();
    	decimalA = decimalA.add(decimalB);
		String s=new String(""+decimalA);
		int I,J,K;
		for(I=0;I<s.length();I++){
			if(s.charAt(I)!='.')
				System.out.print(s.charAt(I));
			else
				break;
			}
		if(I<s.length() && s.charAt(I)=='.' ){
				System.out.print(s.charAt(I));
				for(K=0,J=s.length()-1;J>I;J--)
					if(s.charAt(J)!='0'){
						K=1;
						break;
						}
				if(K==0)
				System.out.println("0");
				else{
					for(I++;I<=J;I++)
						System.out.print(s.charAt(I));
					System.out.println("");
					}
				}
			else
                System.out.println(".0");

		}

  }
}
