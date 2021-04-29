#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

int gcd(int m,int n){
    if(n)
        return gcd( n, m%n );
return m;
}

int main(){
    double pi,total_pair,gcd_pair;
    int T,in;
    while(scanf("%d",&T) && T){
        vector<int> number;
        total_pair=0;gcd_pair=0;
        while(T--){
            cin>>in;
            number.push_back(in);
        }

        for(int I=0;I<number.size()-1;I++){
            for(int J=I+1;J<number.size();J++){
                if(gcd(number[I],number[J])==1)
                        gcd_pair+=1.0;
            total_pair+=1.0;
            }
        }
        if(gcd_pair==0){
            printf("No estimate for this data set.\n");
            continue;
        }
        printf("%.6lf\n",(double)sqrt(6*total_pair/gcd_pair));

    }

return 0;
}
