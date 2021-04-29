#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){

string s;
int I=1;
while(cin>>s && s!="#"){

    if(s=="HELLO")
        printf("Case %d: ENGLISH\n",I);

    else if(s=="HOLA")
        printf("Case %d: SPANISH\n",I);

    else if(s=="HALLO")
        printf("Case %d: GERMAN\n",I);

    else if(s=="BONJOUR")
        printf("Case %d: FRENCH\n",I);

    else if(s=="CIAO")
        printf("Case %d: ITALIAN\n",I);

    else if(s=="ZDRAVSTVUJTE")
        printf("Case %d: RUSSIAN\n",I);
    else
        printf("Case %d: UNKNOWN\n",I);

I++;
}


}
