#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


int main(){

int test,R,C,M,N,alpha[27];
char ch;
//freopen("in.txt","r",stdin);
cin>>test;
for(int I=1;I<=test;I++){
    for(int J=0;J<26;J++)
        alpha[J]=0;
    cin>>R>>C>>M>>N;
    getchar();

    for(int J=0;J<R;J++){
        for(int K=0;K<C;K++){
            ch=getchar();
            alpha[ch-65]++;
        }
    getchar();
    }

    int max=0;

    for(int J=0;J<26;J++)
        if(alpha[J]>max){
            max=alpha[J];
          }
    int count=0;
    for(int J=0;J<26;J++)
        if(alpha[J]==max){
            count+=max;
          }

    cout<<"Case "<<I<<": "<<count*M+((R*C)-count)*N<<endl;
}


return 0;
}
