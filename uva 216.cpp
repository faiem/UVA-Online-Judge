#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

double distance(int x1,int y1,int x2,int y2){

return sqrt(double(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}

double cal_distance;

int main(){

    //freopen("in.txt","r",stdin);
    int node,x,y,T=1;
    while(cin>>node && node){
        pair<int,int> cordinate[node],store[node];
        int per[8]={0,1,2,3,4,5,6,7};
        double min_distance=100000.0;
        for(int I=0;I<node;I++){
            cin>>x>>y;
            cordinate[I]=make_pair(x,y);
        }

        do{
           double total_distance=0.0;
           for(int I=0;I<node-1;I++){
                total_distance+=distance(cordinate[per[I]].first,cordinate[per[I]].second,cordinate[per[I+1]].first,cordinate[per[I+1]].second);
           }
           if(min_distance>total_distance){
                min_distance=total_distance;
                for(int I=0;I<node;I++){
                    //cout<<cordinate[per[I]].first<<" "<<cordinate[per[I]].second<<endl;
                    store[I]=make_pair(cordinate[per[I]].first,cordinate[per[I]].second);
                }
           }
        }while( next_permutation(per,per+node) );

    double measure_distance;
    printf("**********************************************************\n");
    printf("Network #%d\n",T);
    cal_distance=0.0;
    for(int I=0;I<node-1;I++){
        measure_distance=16.0+distance(store[I].first,store[I].second,store[I+1].first,store[I+1].second);
        cal_distance=double(cal_distance+measure_distance);
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",store[I].first,store[I].second,store[I+1].first,store[I+1].second,measure_distance);
    }
    printf("Number of feet of cable required is %.2lf.\n",cal_distance);
    T++;
    }

}
