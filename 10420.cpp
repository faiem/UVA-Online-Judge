#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int n;
    //freopen("in.txt","r",stdin);
    string country;
    cin>>n;
        map<string,int> love;
        map<string,int>::iterator it;
        vector<pair<string,int> > v;
        while(n--){
            cin>>country;
            love[country]++;
                while(getchar()!='\n'){}
            }
        for(it=love.begin();it!=love.end();it++)
          cout<<it->first<<" "<<it->second<<endl;

return 0;
}
