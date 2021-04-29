#include<stdio.h>

int main(){

int test,I,count;
char ch,arr[5];
scanf("%d",&test);
getchar();
while(test--){
    I=0;count=0;
    while((ch=getchar())!='\n'){
        arr[I]=ch;
    I++;
    }
    if(I==5)
        printf("3\n");
    else{
        I=-1;
        if(arr[++I]=='t')
            count++;
        if(arr[++I]=='w')
            count++;
        if(arr[++I]=='o')
            count++;
        if(count>=2)
            printf("2\n");
        else
            printf("1\n");
    }
}

return 0;
}

