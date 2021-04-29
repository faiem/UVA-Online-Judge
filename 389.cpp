#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
using namespace std;

long power(int num,int p){
    long a=1;
    for(int I=0;I<p;I++)
        a*=num;
return a;
}

int convert10base(string s,int base){
    int num=0,a;
    for(int I=0,k=(s.size()-1);I<s.size();I++,k--){
        if(s[I]>=65)
            a=s[I]-55;
        else
            a=s[I]-48;
        num+=a*power(base,k);
        }
return num;
}

stack<char> TenBaseTo36Bases(int num,int base){

    stack<char> st;
    int temp;

    if(num==0)
        st.push(48);

    while(num){
        temp=num%base;
        if(temp>9)
        st.push(55+temp);
        else
        st.push(48+temp);
    num/=base;
    }

return st;
}

void output(string s,int b1,int b2){

stack<char> st;
st=TenBaseTo36Bases(convert10base(s,b1),b2);

    if(st.size()>7)
        printf("  ERROR\n");
    else
        {
            for(int I=0;I<(7-st.size());I++)
                printf(" ");
            while(!st.empty()){
            cout<<st.top();
            st.pop();
            }
        cout<<endl;
        }
}

int main(){
string s;
int b1,b2;

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

while(cin>>s>>b1>>b2){
    output(s,b1,b2);
}

return 0;
}
