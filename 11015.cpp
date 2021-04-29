#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
#define inf 2147483646
long d[23][23];

void clear(int node){

    for(int I=0;I<=node;I++){
        for(int J=0;J<=node;J++){
            d[I][J]=inf;
            d[I][I]=0;
        }
    d[I][I]=0;
    }
}

long min(int a,int b){
    if(a<b)
        return a;
return b;
}
void floyed(int n){

for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            d[i][j]=min(d[i][j],d[i][k] + d[k][j]);

}



int main(){
//freopen("in.txt","r",stdin);
int node,edge,t=1,a,b,cost;


while(cin>>node>>edge && node){
    clear(node);
    string s;
    vector<string> str;

    for(int I=1;I<=node;I++){
        cin>>s;
        str.push_back(s);
        }
        for(int I=0;I<edge;I++){
        cin>>a>>b>>cost;
        d[a][b]=cost;
        d[b][a]=cost;
        }
    floyed(node);
    long place,sum=0,minimum=inf,a;
    for(int I=1;I<=node;I++){
        sum=0;
        for(int J=1;J<=node;J++)
            sum+=d[I][J];
    if(minimum>sum){
        place=I;
        minimum=sum;
        }

    }
    cout<<"Case #"<<t<<" : "<<str[place-1]<<endl;

t++;
}

return 0;
}
