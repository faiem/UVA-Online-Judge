#include<cstdio>
#include<iostream>
using namespace std;

int main(){

unsigned long N_M,ans,ans2;

while(cin>>N_M && N_M){

    ans=(N_M)*10/9;
    if((ans-1)-((ans-1)/10)==N_M){
        ans2=ans-1;
        cout<<ans2<<" "<<ans<<endl;
        }
    else
        cout<<ans<<endl;
    }

return 0;
}
