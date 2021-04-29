#include <stdio.h>
#include <string.h>

char str[1000001],qs[1010];

int main ()
{
  int test,q;
  scanf("%d",&test);
  getchar();
  while(test--){

    gets(str);
    scanf("%d",&q);
    getchar();
    while(q--){
    gets(qs);
    if(strstr(str,qs))
        printf("y\n");
    else
        printf("n\n");
    }
  }
  return 0;
}
