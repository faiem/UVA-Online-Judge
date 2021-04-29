#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool mysort(const string &F,const string &J){
    if((string(F+J))>(string(J+F)))
        return true;
return false;
}

int main(){
int N;
string s;
while(cin>>N && N){
    vector<string> vs;
    while(N--){
    cin>>s;
    vs.push_back(s);
    }
    sort(vs.begin(),vs.end(),mysort);
    for(int I=0;I<vs.size();I++)
        cout<<vs[I];
cout<<endl;
}
return 0;
}
