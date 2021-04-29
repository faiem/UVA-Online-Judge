#include<stdio.h>

int knight(int r,int c){
    if((c&1)==0)
        return ((r*c)/2);
    else if((c&1)==1)
        return ((1+(c/2))*(r/2))+((r/2)*(c/2));
return (1+(r/2))*(1+(c/2))+(r/2)*(c/2);
}

int king(int r,int c){

    return (((r+1)/2)*((c+1)/2));
    }
//queen=rook
int rook(int r,int c){
    if(r>c)
        return c;
return r;
}
int main()
{
    int test,r,c;
    char ch;
    scanf("%d",&test);
    getchar();
    while(test--){
        scanf("%c %d %d",&ch,&r,&c);
        if(ch=='r')
            printf("%d\n",rook(r,c));
        else if(ch=='k')
            printf("%d\n",knight(r,c));
        else if(ch=='Q')
            printf("%d\n",rook(r,c));
        else
            printf("%d\n",king(r,c));

    getchar();
    }

    return 0;
    }
