#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){

    int m,n,t,dp[10000],eat_time[2];
    dp[0]=0;
    while(cin>>eat_time[0]>>eat_time[1]>>t){

        sort(eat_time,eat_time+1);

        for(int I=1;I<=t;I++)
            dp[I]=-1;

        for(int I=0;I<2;I++){
            for(int J=eat_time[I];J<=t;J++)
                if(dp[J-eat_time[I]]!=-1)
                    dp[J]=max(dp[J],dp[J-eat_time[I]]+1);
        }

        /*
        for(int I=0;I<=t;I++)
            cout<<dp[I]<<" ";
        cout<<endl;
        */

        if(dp[t]!=-1)
            cout<<dp[t]<<endl;
        else{
            int burger=0,beer=0;
            for(int I=t-1;I>=0;I--)
                if(dp[I]!=-1){
                    burger=dp[I];
                    beer=t-I;
                    break;
                }
        cout<<burger<<" "<<beer<<endl;
        }


    }

return 0;
}
