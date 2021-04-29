#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
long num;

int anagramList[22]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
while(cin>>num&&num!=0){

if(num>=997)
    cout<<"0\n";
else if((num>=97&&num<=99)||(num>=7&&num<=9))
    cout<<"0\n";
else if(num==1)
    cout<<"2\n";
else
    {
    for(int I=21;I>0;I--){
        if(anagramList[I]>num&&anagramList[I-1]<=num)
            cout<<anagramList[I]<<endl;
        }
    }

}


}
