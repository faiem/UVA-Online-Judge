#include<stdio.h>

int main(){

    char ch;
    int mod;
    while((ch=getchar())!='0'){
        mod=0;
        mod=(mod*10+(ch-48))%17;
        while((ch=getchar())!='\n')
            mod=(mod*10+(ch-48))%17;
        if(mod==0)
            printf("1\n");
        else
            printf("0\n");
    }


return 0;
}
