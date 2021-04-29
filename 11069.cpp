#include<cstdio>
#include<iostream>
using namespace std;

int main(){

long arr[80];
arr[0]=0;
arr[1]=1;
arr[2]=2;
arr[3]=2;
arr[4]=3;
arr[5]=4;

for(int I=6;I<=76;I++)
    arr[I]=arr[I-1]+arr[I-5];

int num;
while(cin>>num){

cout<<arr[num]<<endl;

}

return 0;
}
