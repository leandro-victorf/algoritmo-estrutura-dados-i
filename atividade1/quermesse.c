#include <stdio.h>

int main() {
  int n, ingresso, vencedor;
  int contador = 0;
  
  do{
      scanf("%d", &n);
    if(n != 0) {
    for (int i = 1; i <= n; i++){
      scanf("%d", &ingresso);
      if (ingresso == i){
        vencedor = ingresso;
        contador ++;
      }
    }
    printf("Teste %d\n", contador);
    printf("%d\n\n", vencedor);
    }
  }while(n != 0);
}
  
