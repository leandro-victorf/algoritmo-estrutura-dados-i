#include <stdio.h>

int main() {
  
  int ano;
  scanf("%d", &ano);

  while(ano < 1582 || ano >1000000){
    scanf("%d", &ano);
  }
  float n = ((ano - 1580.0)/4) + 1;
  if( n == (int)n){
    float razao = ano/100.0;
    float razao_dois= ano/400.0;
    if (razao == (int)razao & razao_dois != (int)razao_dois) {
      printf("ANO NAO BISSEXTO\n");
    }else{
      printf("ANO BISSEXTO\n");
    }
  }else{
    printf("ANO NAO BISSEXTO\n");
  }
}
  
