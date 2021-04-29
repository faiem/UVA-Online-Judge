#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
#define MAX -2147483646
using namespace std;

bool cmp(const pair<int,string> &x, const pair<int,string> & y){

        if(x.first>y.first)
            return 1;

return 0;
}

int main(){

int test,p,max;
string s;
//freopen("in.txt","r",stdin);
cin>>test;

    for(int I=1;I<=test;I++){
        max=MAX;
        vector< pair<int,string> > v;
        for(int J=0;J<10;J++){
        cin>>s>>p;
        v.push_back( make_pair(p,s) );
        if(p>max)
            max=p;
        }
    sort(v.begin(),v.end(),cmp);

    cout<<"Case #"<<I<<":\n";
    for(int I=0;I<v.size();I++){
        if(max==v[I].first)
        cout<<v[I].second<<endl;
        else
            break;
        }
    }


return 0;
}
