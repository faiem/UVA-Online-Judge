#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 111
using namespace std;

int mat[MAX][MAX];


int max(int a,int b){
    if(a>b)
        return a;
return b;
}

int solve(int N){
    int I,J,K,sum,res;
    for(I=1;I<=N;I++){
        for(J=1;J<=N;J++){
            mat[I][J]+=mat[I-1][J];
        }
    }
    res=mat[1][1];
    for(I=0;I<N;I++){
        for(J=I+1;J<=N;J++){
            sum=0;
            for(K=1;K<=N;K++){
                sum+=mat[J][K]-mat[I][K];
            if(sum<0)
                sum=0;
            res=max(res,sum);
            }

        }
    }

return res;
}

int main(){

    //freopen("in.txt","r",stdin);

    for(int I=0;I<MAX;I++){
        mat[I][0]=0;
        mat[0][I]=0;
    }

    int test,N,B,r1,r2,c1,c2;
    cin>>test;
    while(test--){
        cin>>N>>B;

        for(int I=1;I<=N;I++)
            for(int J=1;J<=N;J++)
                mat[I][J]=1;

        for(int I=0;I<B;I++){
            vector< pair<int,int> > cordinate;
            cin>>r1>>c1>>r2>>c2;
            cordinate.push_back(make_pair(r1,c1));
            cordinate.push_back(make_pair(r2,c2));
            sort(cordinate.begin(),cordinate.end());
            for(int J=cordinate[0].first;J<=cordinate[1].first;J++){
                for(int K=cordinate[0].second;K<=cordinate[1].second;K++)
                    mat[J][K]=-MAX;
            }
        }
    cout<<solve(N)<<endl;
    }




return 0;
}

