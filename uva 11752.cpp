#include<cstdio>
#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int nonprime[46]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39,40,42,44,45,46,48,49,50,51,52,54,55,56,57,58,60,62,63,64};
//int nonprime[46];
//bool prime[65];
/*
void nonprime_generate(){

    for(int I=0;I<65;I++)
        prime[I]=1;


     prime[1]=0;
     prime[2]=1;
     for(int I=4;I<65;I+=2)
        prime[I]=0;
     for(int I=3;I*I<65;I+=2){
        if(prime[I]){
            for(int J=2*I;J<65;J+=I)
                prime[J]=0;
        }
     }
    int J;
    for(int I=3;I<65;I++){
        if(!prime[I]){
            cout<<I<<endl;
            nonprime[J]=I;
        J++;
        }
    }
cout<<"->"<<J<<endl;
}
*/

unsigned long long power(int x,int y){

    int I;
    unsigned long long result=1;
    for(I=0;I<y;I++)
        result*=x;

return result;
}

int main(){

    //freopen("out.txt","w",stdout);
    //nonprime_generate();
    set<unsigned long long> s;
    set<unsigned long long>::iterator it;


    int I,J;

    s.insert(1);
    for(I=2;I<65537;I++)
        for(J=0;nonprime[J]*log(I) < 64*log(2);J++ )
                s.insert(power(I,nonprime[J]));

    //int c=0;
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<"\n";
    //c++;
    }
    //cout<<c;
return 0;
}
