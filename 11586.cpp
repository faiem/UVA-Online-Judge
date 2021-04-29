#include<cstdio>
#include<iostream>
using namespace std;

int main(){

    int test;
    char ch;
    cin>>test;
    getchar();
    int M,F,count;
    while(test--){
    M=0;F=0;count=0;
    bool flag=0;
    while(1){

        while((ch=getchar())!=' ')
        {
            if(ch=='\n'){
                flag=1;
                break;
            }
            else if(ch=='M')
                    M++;
            else if(ch=='F')
                    F++;
        count++;
        }
        if(flag)
            break;
    }
        if(count>2 && M==F)
            cout<<"LOOP"<<endl;
        else
            cout<<"NO LOOP"<<endl;

    }


return 0;
}
