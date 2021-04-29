#include<stdio.h>

int main(){
    int n,I,c,a,L=0;

     char ch[]={"ABCDE"};
    while(scanf("%d",&n)&&n){

        while(n--){
        c=0;
        for(I=0;I<5;I++){
            scanf("%d",&a);
            if(a<=127){
                c++;
                L=I;
                }
            }
         if(c==1)
            printf("%c\n",ch[L]);
         else
            printf("*\n");
        }

    }

return 0;
}
