#include<stdio.h>

int main(){

long l;
while(scanf("%ld",&l) && l>0){

    if(l==1)
        printf("0%\n");
    else
    printf("%ld%\n",l*25);

}


return 0;
}


