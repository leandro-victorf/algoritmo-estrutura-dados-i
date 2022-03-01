#include <stdio.h>

int main() {
  int corte;
  int regioes;

  scanf("%d", &corte);
  regioes = 1 + ((corte * (1 + corte))/2);

  printf("%d\n", regioes);
}
  
