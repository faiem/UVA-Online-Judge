#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char ch,sen[110][110];
    for(int I=0;I<110;I++)
        for(int J=0;J<110;J++)
            sen[I][J]='\0';
    int line,max,L;
    line=0;max=-1;L=0;

    while((ch=getchar())!=EOF){
        if(ch=='\n'){
            if(max<L)
                max=L;
            line++;
            L=0;
        continue;
        }
        sen[line][L++]=ch;
    }
    //cout<<line<<" "<<max<<endl;
    for(int I=0;I<max;I++){
        stack<char> st;
        for(int J=0;J<line;J++){
            if(sen[J][I]=='\0')
                st.push(' ');
            else
                st.push(sen[J][I]);
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
            }
        printf("\n");
    }

return 0;
}
