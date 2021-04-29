#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<stdlib.h>
using namespace std;

int main(){
int test,N,M,in;
    cin>>test;
    while(test--){
        map<int,int> MAP;
        map<int,int>::iterator it;

        cin>>N>>M;
        while(N--){
            cin>>in;
            MAP[in]++;
        }
        while(M--){
            cin>>in;
            MAP[in]--;
        }
        int sum=0;
        for(it=MAP.begin();it!=MAP.end();it++)
                sum += abs((*it).second);
        cout<<sum<<endl;
    }

return 0;
}
