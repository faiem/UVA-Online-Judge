#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main(){
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int T=0,test,num;
char ch;
cin>>test;
while(test--){

if(T>0)
    printf("\n");
map<vector<int>,int> M;
map<vector<int>,int>::iterator it;

int value[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
cin>>num;
getchar();

while(num--){
    vector<int> v;
    while((ch=getchar())!='\n'){
        if(ch>=65&&ch<=90){
            v.push_back(value[ch-65]);
        }
        else if(ch>=48&&ch<=57)
            v.push_back(ch-48);

    }
    M[v]++;
}
bool dup=0;
//int U=1;
for(it=M.begin();it!=M.end();it++){
    if(it->second>1){
    dup=1;
    for(int I=0;I<3;I++)
        cout<<it->first[I];
    cout<<"-";
  //  cout<<U++<<" ";
    for(int I=3;I<it->first.size();I++)
        cout<<it->first[I];
    cout<<" "<<it->second<<endl;
    }
}

    if(!dup)
        printf("No duplicates.\n");

T++;
}
return 0;
}
