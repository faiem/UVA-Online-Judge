#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

long num[202];
int dp[210][202][12],n,M,D,arr[202];


int div_sum(int sum,int i,int k){


    if(i>n || k<0)
        return 0;

    else if(dp[sum][i][k]!=-1)
        return dp[sum][i][k];

    else if(k==0){
        if(sum%D==0)
            return 1;
    return 0;
    }

return dp[sum][i][k]=div_sum(sum+arr[i],i+1,k-1)+div_sum(sum,i+1,k);
}

int mod(int n,int m)
{
	if(n<0)
		n+=(ceil(-n*1.00/m)*m);
	return n%m;
}

int main(){

    //freopen("in.txt","r",stdin);
    int q,c=1;

    while(cin>>n>>q && n){

        for(int i=0;i<n;i++)
            cin>>num[i];
        cout<<"SET "<<c<<":\n";
        for(int i=0;i<q;i++){
            cin>>D>>M;
            cout<<"QUERY "<<i+1<<": ";
            memset(dp,-1,sizeof(dp));
            for(int i=0;i<n;i++)
                arr[i]=mod(num[i],D);
            cout<<div_sum(0,0,M)<<endl;
        }
    c++;
    }


return 0;
}
