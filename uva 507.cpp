#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 20010

int stop[MAX],interval[MAX];


int main(){


    //freopen("in.txt","r",stdin);
    int test,s,N,Fs,max_length,length,max_value;

    cin>>test;
    for(int K=1;K<=test;K++){

        cin>>N;
        for(int J=1;J<N;J++){
            cin>>stop[J];
        }
        s=0;
        Fs=0;
        max_length=0;
        max_value=interval[0]=-10000000;
        interval[N]=interval[0];
        for(int I=1;I<N;I++){
            if(interval[I-1]<0){
                s=I;
                length=0;
                interval[I]=stop[I];
            //continue;
            }
            else
            interval[I]=interval[I-1]+stop[I];
            //cout<<"->"<<interval[I]<<endl;
            if(max_value==interval[I]){
                if(max_length<length){
                    max_length=length;
                }
            }
            if(max_value<interval[I]){
                Fs=s;
                max_value=interval[I];
                max_length=length;
            }
        length++;
        }
    /*
    for(int I=1;I<N;I++)
        cout<<interval[I]<<" ";
    cout<<endl;
    */
    if(max_value<0)
        printf("Route %d has no nice parts\n",K);
    else
        printf("The nicest part of route %d is between stops %d and %d\n",K,Fs,Fs+max_length+1);
    }


return 0;
}

