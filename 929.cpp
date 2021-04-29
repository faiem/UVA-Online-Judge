#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define INF 2147483647

class faiem{

    int cost,row,col;

 public:

    faiem(int c,int r,int co){
        cost=c;
        row=r;
        col=co;
    }

    int Row()const{
    return row;
    }

    int Col()const{
    return col;
    }

    int Cost()const{
    return cost;
    }

};


bool operator<(const faiem &a, const faiem &b ){

    if( a.Cost() >= b.Cost() )
        return true;

return false;
}

int main(){

    int test,R,C, mat[1000][1000],dis[1000][1000];
    //freopen("in.txt","r",stdin);
    cin>>test;
    while(test--){
    priority_queue<faiem> pq;
    cin>>R>>C;
    for(int I=0;I<R;I++){
        for(int J=0;J<C;J++){
            cin>>mat[I][J];
            dis[I][J]=INF;
        }
    }
    pq.push(faiem(mat[0][0],0,0));
    dis[0][0]=mat[0][0];
    int r,c,cost;
    while(!pq.empty()){
        r=pq.top().Row();
        c=pq.top().Col();
        cost=pq.top().Cost();
        pq.pop();

        if(r-1>=0&&(cost+mat[r-1][c])<dis[r-1][c]){
            dis[r-1][c]=cost+mat[r-1][c];
            pq.push(faiem(cost+mat[r-1][c],r-1,c));
            }

        if(r+1<R&&(cost+mat[r+1][c])<dis[r+1][c]){
            dis[r+1][c]=cost+mat[r+1][c];
            pq.push(faiem(cost+mat[r+1][c],r+1,c));
            }

        if(c-1>=0&&(cost+mat[r][c-1])<dis[r][c-1]){
            dis[r][c-1]=cost+mat[r][c-1];
            pq.push(faiem(cost+mat[r][c-1],r,c-1));
            }

        if(c+1<C&&(cost+mat[r][c+1])<dis[r][c+1]){
            dis[r][c+1]=cost+mat[r][c+1];
            pq.push(faiem(cost+mat[r][c+1],r,c+1));
            }


        }

    cout<<dis[R-1][C-1]<<endl;
    }
return 0;
}
