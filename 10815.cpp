#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int main(){
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

string s;
int I=0;
char arr[201],ch;
map<string,string> M;
map<string,string>::iterator it;

while((ch=getchar())){

    if(ch>=65&&ch<=90){
        ch+=32;
        arr[I]=ch;
        }
    else if(ch>=97&&ch<=122)
        arr[I]=ch;

    else{

        arr[I]='\0';
        s=arr;
        M[s]=s;
        I=-1;
        if(ch==EOF)
            break;
    }
I++;
}



    M.erase("");

    for(it=M.begin();it!=M.end();it++,I++){
        cout<<(*it).first<<endl;
        }
return 0;
}
