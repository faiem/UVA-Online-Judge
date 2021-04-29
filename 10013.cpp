#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int test,T=0,M,d1,d2;
cin>>test;

while(test--){
    if(T>0)
        printf("\n");
    stack<pair<int,int> > s;
    stack<int> result;

    cin>>M;
    while(M--){
    cin>>d1>>d2;
    s.push(make_pair(d1,d2));
    }
    int carry=0,sum;
    while(s.size()){
        sum=carry+s.top().first+s.top().second;
        if(sum>9){
            result.push(sum-10);
            carry=1;
            }
        else{
            result.push(sum);
            carry=0;
            }
    s.pop();
    }
    if(carry)
        result.push(carry);
    while(result.size()){
        cout<<result.top();
    result.pop();
    }
cout<<endl;
T++;
}


return 0;
}
