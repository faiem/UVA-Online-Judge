#include<stdio.h>


int vowel(char ch){

    if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
        return 1;
return 0;
}

int main(){
int v;
char ch,c;
while((ch=getchar())!=EOF){
    v=0;
    if((ch>64&&ch<91)||(ch>96&&ch<123)){
        if(vowel(ch)){
        v=1;
        printf("%c",ch);
        }
        else
            c=ch;
        while((ch=getchar())&&((ch>64&&ch<91)||(ch>96&&ch<123))){
            printf("%c",ch);
        }
        if(v==0)
           printf("%c",c);
        printf("ay");
    }
    printf("%c",ch);
}


return 0;
}
