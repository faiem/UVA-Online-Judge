#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int main(){

long N,M,in;
while(cin>>N>>M && N){
    map<int,bool> jack;
    while(N--){
        cin>>in;
        jack[in]=true;
    }
    N=0;
    while(M--){
        cin>>in;
        if(jack[in])
            N++;
    }
    cout<<N<<endl;
}

return 0;
}
