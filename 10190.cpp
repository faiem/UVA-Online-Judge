#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(){
long a,b,mod,div;
while(scanf("%ld %ld",&a,&b)==2){
vector<long> v;
bool flag=0;

   if (a<2||b<2||b>a) {
            cout<<"Boring!\n";
            continue;
        }

v.push_back(a);
while(a>1){
    div=a/b;
    mod=a%b;
    if(mod>0){
        flag=1;
        break;
        }
    v.push_back(div);
    a=div;
    }
if(flag)
    cout<<"Boring!"<<endl;
else{
cout<<v[0];
for(int J=1;J<v.size();J++)
    cout<<" "<<v[J];
cout<<endl;
}

}


return 0;
}
