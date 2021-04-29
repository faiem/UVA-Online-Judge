#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string binum[4202];

int main(){

vector<int> bit;
bit.push_back(0);
bit.push_back(1);
binum[0]="0";
binum[1]="1";

    for(int I=1;I<=2100;I++)
    {
        bit.push_back(bit[I]);
        binum[I*2]=binum[I]+"0";
        bit.push_back(bit[I]+1);
        binum[(I*2)+1]=binum[I]+"1";
        }
int test,k;
cin>>test;
while(test--){
bool flag=false;
int x,y;
    scanf("%x",&x);
    getchar();
    if(getchar()=='+')
        flag=true;
    getchar();
    scanf("%x",&y);
    if(flag){
        k=13-binum[x].size();
        for(int I=1;I<=k;I++)
            printf("0");
        cout<<binum[x]<<" + ";

        k=13-binum[y].size();
        for(int I=1;I<=k;I++)
            printf("0");
        cout<<binum[y]<<" ";
    printf("= %d\n",x+y);
    }
else{
    k=13-binum[x].size();
    for(int I=1;I<=k;I++)
        printf("0");
    cout<<binum[x]<<" - ";
    k=13-binum[y].size();
    for(int I=1;I<=k;I++)
        printf("0");
    cout<<binum[y]<<" ";
    printf("= %d\n",x-y);
    }
}
return 0;
}
