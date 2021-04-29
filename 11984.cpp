#include<iostream>
#include<cstdio>
using namespace std;

int main(){
int test,c,d;
double f;
cin>>test;
for(int I=1;I<=test;I++){
    cin>>c>>d;
    f=((9.00/5.00)*(double)c)+32;
    f+=d;
    printf("Case %d: %.2lf\n",I,(double)(((f-32)*5)/9));
}

return 0;
}
