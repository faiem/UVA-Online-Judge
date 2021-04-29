#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int LDS(vector<int> H,vector<int> L){

    int add[H.size()],max_lenght=0;

    for(int I=0;I<H.size();I++){
        add[I]=L[I];
        for(int J=0;J<I;J++)
            if(H[J]>H[I]){
                add[I]=max(add[I],add[J]+L[I]);
            }
    }

    for(int I=0;I<H.size();I++)
        max_lenght=max(max_lenght,add[I]);

return max_lenght;
}


int main(){

    //freopen("in.txt","r",stdin);
    int test,n,h,l,lis,lds;
    cin>>test;
    for(int I=1;I<=test;I++){
        cin>>n;
        vector<int> hight(n),length(n);
        for(int J=0;J<n;J++)
            cin>>hight[J];
        for(int J=0;J<n;J++)
            cin>>length[J];
        lds=LDS(hight,length);
        reverse(hight.begin(),hight.end());
        reverse(length.begin(),length.end());
        lis=LDS(hight,length);
        if(lis>=lds)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",I,lis,lds);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",I,lds,lis);

    }




return 0;
}

