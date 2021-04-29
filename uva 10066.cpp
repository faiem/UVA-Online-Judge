//submit korsi but UVA down
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX 200

vector<int> s1,s2;
int matrix_value[MAX][MAX],C;

int LCS(){

    for(int I=1;I<=s1.size();I++)
        matrix_value[0][I]=0;
    for(int I=1;I<=s2.size();I++)
        matrix_value[I][0]=0;

    for(int I=1;I<=s1.size();I++){
        for(int J=1;J<=s2.size();J++){
            if(s1[I-1]==s2[J-1]){
                matrix_value[I][J]=matrix_value[I-1][J-1]+1;
                //matrix_direction[I][J]=1; // 1 means corner
            }

            else if(matrix_value[I-1][J]>=matrix_value[I][J-1]){
                matrix_value[I][J]=matrix_value[I-1][J];
                //matrix_direction[I][J]=2; // 2 means up
            }

            else{
                matrix_value[I][J]=matrix_value[I][J-1];
                //matrix_direction[I][J]=3; // 3 means leftside
            }

        }
    }

return matrix_value[s1.size()][s2.size()];
}






int main(){

    //freopen("in.txt","r",stdin);
    int N1,N2,in,C=1;
    while(scanf("%d %d",&N1,&N2) && N1){

        while(N1--){
            scanf("%d",&in);
            s1.push_back(in);
        }
        while(N2--){
            scanf("%d",&in);
            s2.push_back(in);
        }
    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",C,LCS());
    s1.clear();
    s2.clear();
    C++;
    }

return 0;
}

