#include<stdio.h>

struct shopping{
    int price,weight;
};

shopping S[1001];
int dp[1001][35],P[35];

void clear(int N){
    int I,J;
    for(I=0;I<=N;I++){
        for(J=0;J<35;J++)
            dp[I][J]=-1;
    }
    for(int I=0;I<35;I++){
        dp[N][I]=0;
    }
}

int max(int a,int b){
    if(a>b)
        return a;
return b;
}

int max_value_found(int I,int w,int val,int max_weight){

    int profit1,profit2;

    if(dp[I][w]!=-1)
        return dp[I][w];

    if(w+S[I].weight<=max_weight)
        profit1=S[I].price+max_value_found(I+1,w+S[I].weight,val+S[I].price,max_weight);
    else
        profit1=0;

    profit2=max_value_found(I+1,w,val,max_weight);

return dp[I][w]=max(profit1,profit2);
}


int main(){


    //freopen("in.txt","r",stdin);


    int test,I,obj,person,carry_weight,max_value;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&obj);
        for(I=0;I<obj;I++){
            S[I].price=0;
            S[I].weight=0;
        }
        for(I=0;I<obj;I++){
            scanf("%d %d",&S[I].price, &S[I].weight);
        }
        max_value=0;
        for(int I=0;I<35;I++)
            P[I]=-1;
        scanf("%d",&person);
        while(person--){
            scanf("%d",&carry_weight);

            if(P[carry_weight]==-1){
                clear(obj);
                P[carry_weight]=max_value_found(0,0,0,carry_weight);
                max_value+=P[carry_weight];
            }
            else
                max_value+=P[carry_weight];
        //printf("->%d %d\n",carry_weight,P[carry_weight]);
        }

        printf("%d\n",max_value);
    }



return 0;
}
