#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#include<cmath>
#include<queue>
using namespace std;

class Faiem{

int joint;
double dis;

public:

    Faiem(double D,int J){
        dis=D;
        joint=J;
    }

    double Distance()const{
    return dis;
    }

    int Joint()const{
    return joint;
    }
};

bool operator<(const Faiem &p1,const Faiem &p2){

    if(p1.Distance() >= p2.Distance())
        return true;
return false;
}


int main(){

bool flag[101];
int test,CN;
double x,y,d;//dis[101][101];
    cin>>test;

    while(test--){
        cin>>CN;
        vector< pair<double,double> > v;
        vector<Faiem> distance[CN];
        priority_queue<Faiem> PQ;

        for(int I=0;I<101;I++)
            flag[I]=0;

        while(CN--){
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }

        for(int I=0;I<v.size();I++){
            for(int J=I+1;J<v.size();J++){
            d=sqrt((v[I].first-v[J].first)*(v[I].first-v[J].first)+(v[I].second-v[J].second)*(v[I].second-v[J].second));
            //dis[I][J]=dis[J][I]=d;
            distance[I].push_back(Faiem(d,J));
            distance[J].push_back(Faiem(d,I));
            }
        }
/*
        for(int I=0;I<v.size();I++){
            for(int J=0;J<v.size();J++){
            cout<<dis[I][J]<<" ";
            }
        cout<<"\n";
        }
        cout<<endl;
*/
        PQ.push( Faiem(0,0) );
        double line=0;
        int j;
        while(!PQ.empty()){

            j=PQ.top().Joint();
            if(flag[j])
               PQ.pop();
            //cout<<PQ.top().Distance()<<" "<<PQ.top().Joint()<<endl;
            else{
            flag[j]=true;
            line+=PQ.top().Distance();
            PQ.pop();
            for(int I=0;I<distance[j].size();I++)
                if(!flag[ distance[j][I].Joint() ])
                    PQ.push(Faiem(distance[j][I].Distance(),distance[j][I].Joint()));
            }
        }
    printf("%.2lf\n",line);
    if(test>0)
        cout<<endl;
    }

return 0;
}
