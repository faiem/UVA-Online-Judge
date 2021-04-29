#include<stdio.h>
#include<math.h>

double arr[10000000];

void count_digit(long a){
  double sum;
  arr[0]=1;
  sum=0;
  int i;
  for(i=1;i<=a;i++){
   sum+=log10(i);
   arr[i]=floor(sum)+1;
  }
}


int main(){

    int test,fact;
    count_digit(10000000);
    scanf("%d",&test);
    while(test--){
     scanf("%d",&fact);
     printf("%.lf\n",arr[fact]);
    }

return 0;
}
