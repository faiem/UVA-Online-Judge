#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
using namespace std;

long power(long num,long p){
    long a=1;
    for(long I=0;I<p;I++)
        a*=num;
return a;
}

long convert10base(string s,long base){
    long num=0,a,invalid=-1;
    for(long I=0,k=(s.size()-1);I<s.size();I++,k--){
        if(s[I]>=65)
            a=s[I]-55;
        else
            a=s[I]-48;
        if(a>base-1){
            num=invalid;
            break;
            }
        num+=a*power(base,k);
        }
return num;
}

stack<char> TenBaseTo36Bases(long num,long base){

    stack<char> st;
    long temp;

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

int main(){

long number;
long bn,cb;
string s;
stack<char> st;
    while(cin>>bn>>cb>>s){

    number=convert10base(s,bn);
    if(number<0){
        cout<<s;
        printf(" is an illegal base %ld number\n",bn);
        }
    else{
    st=TenBaseTo36Bases(number,cb);
    cout<<s;
    printf(" base %ld = ",bn);
    while(!st.empty()){
    cout<<st.top();
    st.pop();
    }
    printf(" base %ld\n",cb);
    }

    }

return 0;
}
