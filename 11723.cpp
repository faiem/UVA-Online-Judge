#include<cstdio>
#include<iostream>
using namespace std;

int main(){

int R,N,c=1;
while(cin>>R>>N && R){
    bool flag=1;
    for(int I=1;I<=27;I++)
        if(I*N>=R){
            printf("Case %d: %d\n",c,I-1);
            flag=0;
            break;
            }
    if(flag)
        printf("Case %d: impossible\n",c);
    c++;
    }
return 0;
}
