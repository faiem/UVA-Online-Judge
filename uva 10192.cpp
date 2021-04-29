//submit korsi but UVA down
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
#define MAX 150

char s1[MAX],s2[MAX];
int matrix_value[MAX][MAX];

int LCS(){

    int size1=strlen(s1);
    int size2=strlen(s2);

    for(int I=1;I<=size1;I++)
        matrix_value[0][I]=0;
    for(int I=1;I<=size2;I++)
        matrix_value[I][0]=0;

    for(int I=1;I<=size1;I++){
        for(int J=1;J<=size2;J++){
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

return matrix_value[size1][size2];
}






int main(){

    //freopen("in.txt","r",stdin);
    int C=1;
    while(gets(s1) && s1[0]!='#'){
    gets(s2);
    printf("Case #%d: you can visit at most %d cities.\n",C,LCS());
    C++;
    }


return 0;
}


