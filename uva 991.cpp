#include<stdio.h>
#define limit 10

    int cataline[11];

    void number_generate(){
        int I;
        cataline[0]=1;
        for(I=1;I<=limit;I++){
            cataline[I]=((2*(2*(I-1) + 1)*cataline[I-1])/(I+1));
        }

    }


int main(){

     int n;

     number_generate();
     scanf("%d",&n);
        printf("%d\n",cataline[n]);

     while(scanf("%d",&n)!=EOF){
        printf("\n%d\n",cataline[n]);
     }
return 0;
}
