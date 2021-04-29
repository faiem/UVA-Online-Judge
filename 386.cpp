#include<stdio.h>

int main(){

  long I,J,K,L;
  for(I=6;I<201;I++){
    for(J=2;J<I;J++){
        for(K=J;K<I;K++){
            for(L=K;L<I;L++){
                if((I*I*I)==((J*J*J)+(K*K*K)+(L*L*L))){
                printf("Cube = %d, Triple = (%d,%d,%d)\n",I,J,K,L);
                break;
                }
            }
        }
    }
  }



return 0;
}
