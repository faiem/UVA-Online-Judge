//submit korsi but UVA down
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX 200

vector<string> s1,s2;
int matrix_value[MAX][MAX],matrix_direction[MAX][MAX],C;

void LCS(){

    for(int I=1;I<=s1.size();I++)
        matrix_value[0][I]=0;
    for(int I=1;I<=s2.size();I++)
        matrix_value[I][0]=0;

    for(int I=1;I<=s1.size();I++){
        for(int J=1;J<=s2.size();J++){
            if(s1[I-1]==s2[J-1]){
                matrix_value[I][J]=matrix_value[I-1][J-1]+1;
                matrix_direction[I][J]=1; // 1 means corner
            }

            else if(matrix_value[I-1][J]>=matrix_value[I][J-1]){
                matrix_value[I][J]=matrix_value[I-1][J];
                matrix_direction[I][J]=2; // 2 means up
            }

            else{
                matrix_value[I][J]=matrix_value[I][J-1];
                matrix_direction[I][J]=3; // 3 means leftside
            }

        }
    }

//return matrix_value[s1.size()][s2.size()];
}


void printLCS(int m,int n){

    if(m==0 || n==0)
        return;
    else if(matrix_direction[m][n]==1){
    C++;
        printLCS(m-1,n-1);
        if(C==1)
        cout<<s1[m-1]<<"\n";
        else
        cout<<s1[m-1]<<" ";
    C--;
    }
    else if(matrix_direction[m][n]==2){
        printLCS(m-1,n);
    }
    else
        printLCS(m,n-1);
}





int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s;

    while(cin>>s){

        if(s=="#"){
            while(cin>>s){
                if(s=="#")
                    break;
                s2.push_back(s);
                }
            LCS();
            printLCS(s1.size(),s2.size());
            s1.clear();
            s2.clear();
            continue;
            }
    s1.push_back(s);
    }

return 0;
}

