#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define PI acos(-1)
int main(){
    double D,V;
    while(cin>>D>>V && D!=0){

        printf("%.3lf\n",(double)cbrt((D*D*D)-((6*V)/PI)));

    }


return 0;
}
