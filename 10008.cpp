#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

bool mysort(const pair<int,char> &a,const pair<int,char> &b){
    if(a.first>b.first)
        return true;
return (a.second<b.second);
}


int main(){
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

char ch;
int test,arr[26];
while(cin>>test){
    getchar();
    vector<pair<int,char> > v;
    for(int I=0;I<26;I++)
        arr[I]=0;
    while(test--){
        while((ch=getchar())!='\n'){
            if(ch>=65&&ch<=90)
                ch+=32;
            if(ch>=97&&ch<=122)
                arr[ch-97]++;
        }
    }
    for(int I=0;I<26;I++)
        if(arr[I]>0)
            v.push_back(make_pair(arr[I],I+65));

    sort(v.begin(),v.end(),mysort);
    for(int I=0;I<v.size();I++)
        cout<<v[I].second<<" "<<v[I].first<<endl;

}


return 0;
}

