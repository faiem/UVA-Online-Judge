#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[20];
    long F;
    while( gets(s) ){
        if(strlen(s)>1 && s[0]=='0' && s[1]=='x'){
            F=strtol(s,NULL,16);
            printf("%ld\n",F);
        }
        else{
            F=atol(s);
            if(F<0)
                break;
            printf("0x%X\n",F);
        }

    }

return 0;
}
