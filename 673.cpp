#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main(){
bool flag;
char ch,ch2;
int test;

cin>>test;
getchar();

while(test--){
    stack<char> s;
    flag=0;
    while((ch=getchar())!='\n'){
        //cout<<ch<<endl;
        if(flag==1){}

        else if(ch=='('||ch=='[')
           s.push(ch);

        else if(ch==')'||ch==']'){
            if(s.empty()){
                flag=1;
            ch2='A';
            }
            else if(s.top()=='(')
                ch2=')';
            else if(s.top()=='[')
                ch2=']';

            if(ch2!=ch){
                flag=1;
            //    cout<<ch2<<"->"<<ch<<endl;
                }
            else
            s.pop();
            }
        }

    if(flag||!s.empty())
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;

    }



return 0;
}
