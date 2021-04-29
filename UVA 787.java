 
import java.util.*;
import java.math.*; 
 

 class Main {
        
    static BigInteger max(BigInteger A,BigInteger B){
    	if(A.compareTo(B)>0)
    		return A;
    return  B;
    }
    
    
    public static void main(String[] args) {
        
        Scanner scan=new Scanner(System.in);
        BigInteger input,max_Big,product;
	BigInteger B[]=new BigInteger[200];
        	        
	while(scan.hasNextBigInteger()){
        	int c=0;
        	while(true){
        		input=scan.nextBigInteger();
        		if(input.compareTo(new BigInteger("-999999"))==0)
        			break;
        		B[c]=input;	
        	c++;	
        	}
        	max_Big=new BigInteger("-1000000000");
        	for(int I=0;I<c;I++){
        		for(int J=I;J<c;J++){
        			product=new BigInteger("1");
        			for(int K=I;K<=J;K++){
        				product=product.multiply(B[K]);
        				max_Big=max(max_Big,product);
        			}
        		}
        	}
        	System.out.println(""+max_Big);
        }
        
        
        
        
        
        
    }
}
