#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

int main(){

//freopen("in.txt","r",stdin);
int m,n;

while(cin>>m>>n){

map<string,long> hey;
string s;
long doller;
    while(m--){
        cin>>s>>doller;
        hey[s]=doller;
    }

    while(n--){
        doller=0;
    while(cin>>s && s!="."){
        if(hey[s])
            doller+=hey[s];
    }
    cout<<doller<<endl;
    }
}



return 0;
}
