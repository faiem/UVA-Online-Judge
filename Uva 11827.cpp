#include<cstdio>
#include<iostream>
#include<cmath>
#include<sstream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int gcd(int m, int n) {

    if (n)
        return gcd(n, m % n);
    return m;
    }

int max(int a,int b){
    if(a>b)
        return a;
return b;
}

int main(){


        int T,number,maxGcd;
        cin>>T;
        getchar();
        while(T--){

            maxGcd=0;
            vector<int> v;
            string line;
            stringstream inputLine;

            getline(cin,line);
            inputLine<<line;

            while(inputLine>>number){
                v.push_back(number);
                }

            for(int I=0;I<v.size()-1;I++){
                for(int J=I+1;J<v.size();J++){
                    maxGcd=max(maxGcd,gcd(v[I],v[J]));
                    }
                }

        cout<<maxGcd<<endl;
        }



return 0;
}
