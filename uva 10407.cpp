#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int gcd(int m, int n) {

   if (n)
    return gcd(n, m % n);
return m;
}



int main(){

    int in;
    while(scanf("%d",&in) && in){
        vector<int> number;
        number.push_back(in);
        while(scanf("%d",&in) && in)
            number.push_back(in);
        sort(number.begin(),number.end());
        in=number[1]-number[0];
        for(int I=1;I<number.size()-1;I++)
            in=gcd(in,number[I+1]-number[I]);
    printf("%d\n",in);
    }


return 0;
}
