#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>
using namespace std;
#define PI 3.14159265

int main(){
    int num,cal;
    vector<int> v;
    v.push_back(1);

    for(int i=1;i<=1000000;i++){
           cal=v[(int)floor(i-sqrt(i))]+v[(int)floor(log(i))]+v[(int)floor(i*sin(i)*sin(i))];
           v.push_back(cal%1000000);
    }


    while(cin>>num&&num>=0){

    cout<<v[num]<<endl;

    }


return 0;
}
