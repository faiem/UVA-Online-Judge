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
char arr[201],ch,d;
map<string,string> M;
map<string,string>::iterator it;

while((ch=getchar())){

    if(ch=='-'){
        d=getchar();
        if(d!='\n'){
            arr[I]=ch;
            I++;
            arr[I]=d;
        I++;
        }
    }
    else if(ch>=65&&ch<=90){
        ch+=32;
        arr[I]=ch;
        I++;
        }
    else if(ch>=97&&ch<=122){
        arr[I]=ch;
    I++;
    }
    else{

        arr[I]='\0';
        s=arr;
        M[s]=s;
        I=-1;
        if(ch==EOF)
            break;
    I++;
    }

}



    M.erase("");

    for(it=M.begin();it!=M.end();it++,I++){
        cout<<(*it).first<<endl;
        }
return 0;
}
