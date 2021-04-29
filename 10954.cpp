#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int main(){

    long a,total,sum,b;
    while(cin>>a&&a!=0){
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int I=0;I<a;I++){
        cin>>b;
        pq.push(b);
        }
    total=0;
    sum=0;
    while(pq.size()>=2){
        sum=0;
        sum+=pq.top();
        pq.pop();
        sum+=pq.top();
        pq.pop();
        total+=sum;
        pq.push(sum);
        }
    cout<<total<<endl;
    }




return 0;
}
