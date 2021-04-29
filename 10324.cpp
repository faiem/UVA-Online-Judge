#include<stdio.h>


int compare(char s[1000001],int start,int end){

    int I;

    if(start==end)
        return 1;

    for(I=start;I<end;I++)
        if(s[I]^s[I+1])
            return 0;
return 1;
}

int main(){

    int q,c=0,a,b;
    char str[1000001];

        while( scanf("%s",str)==1){

        scanf("%d",&q);

        printf("Case %d:\n",++c);

        while(q--){

            scanf("%d %d",&a,&b);
            int flag;

            if(a>=b)
                flag=compare(str,b,a);
            else
                flag=compare(str,a,b);

            if(flag)
                printf("Yes\n");
            else
                printf("No\n");

            }

        }

return 0;
}
