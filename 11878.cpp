#include<stdio.h>

int main(){
    int a,b,c,r=0;
char ch,s;
while((scanf("%d%c%d%c%d",&a,&ch,&b,&s,&c))!=-1){
        if(getchar()=='?'){}
        else if(ch=='+'){
            if((a+b)==c)
                r++;
        }
        else if(ch=='-'){
            if((a-b)==c)
                r++;
        }

}
printf("%d\n",r);


return 0;
}
