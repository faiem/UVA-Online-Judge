#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){

    int test,a[4];
    cin>>test;
    while(test--){

        for(int I=0;I<4;I++){
            cin>>a[I];
        }
        sort(a,a+4);
        if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
            printf("square\n");
        else if(a[0]==a[1]&&a[2]==a[3])
            printf("rectangle\n");
        else if((a[0]+a[1]+a[2])>a[3])
            printf("quadrangle\n");
        else
            printf("banana\n");


    }

return 0;
}
