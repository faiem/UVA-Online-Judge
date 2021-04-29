#include<stdio.h>
#include<stdlib.h>

int main(){
    int check;
    char s[1000],t[1000],ch;
    long double a,b;
    while(scanf("%s %c %s",s,&ch,t)==3){
        check=0;
        printf("%s %c %s\n",s,ch,t);
        a=atof(s);
        b=atof(t);

        if(a>2147483647){
            printf("first number too big\n");
        }
        if(b>2147483647){
            printf("second number too big\n");
        }


            if(ch=='+'){
                a+=b;
                if(a>2147483647)
                    printf("result too big\n");
            }
            else{
                a*=b;
                if(a>2147483647)
                    printf("result too big\n");
            }


    }

return 0;
}
