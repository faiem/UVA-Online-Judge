#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

class anagram{
map<string,string> m;
map<string,string>::iterator it;

map<string,int> ms;
set<string> print;
set<string>::iterator is;

string s;
public:
    anagram(){
        while(cin>>s && s!="#"){
            process(s);
            }
        for(it=m.begin();it!=m.end();it++)
            if(ms.find(it->first)->second==1)
                print.insert(it->second);
                //cout<<it->second<<endl;
        for(is=print.begin();is!=print.end();is++)
            cout<<(*is)<<endl;
        }

    char lower(char c){
        if(c<97)
            return (c+32);
    return c;
    }

    void process(string a){
        char str[30];
        string p;
        for(int I=0;I<a.size();I++){
            str[I]=lower((char)a[I]);
        }
        sort(str,str+a.size());
        str[a.size()]='\0';
        p=str;
        ms[p]++;
        m[p]=a;
    }

};


int main(){
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

anagram A;

return 0;
}
