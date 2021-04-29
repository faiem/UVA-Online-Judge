#include<stdio.h>

int main(){

    int mod=131071,result=0;
    char ch;
    while((ch=getchar())!=EOF){

        if(ch=='#'){
            if(result==0)
                printf("YES\n");
            else
                printf("NO\n");
            result=0;

            }
        else if(ch!='\n')
            result=(result*2+(ch-48))%mod;
    }

return 0;
}
