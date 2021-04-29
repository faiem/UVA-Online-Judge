#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    int num,index[10],test;
    vector<int> v[10001];
    //freopen("in.txt","r",stdin);
    for(int I=1;I<=10000;I++){
        num=I;
        while(num>0){
            v[I].push_back(num%10);
            num/=10;
        }
    }
    cin>>test;
    while(test--){
        cin>>num;
        for(int I=0;I<10;I++)
            index[I]=0;
        for(int I=1;I<=num;I++)
            for(int J=0;J<v[I].size();J++)
                index[ v[I][J] ]++;
    for(int I=0;I<9;I++)
        cout<<index[I]<<" ";
    cout<<index[9]<<endl;
    }

return 0;
}
