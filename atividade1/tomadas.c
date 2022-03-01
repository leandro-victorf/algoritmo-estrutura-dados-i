#include <stdio.h>

int main() {
  int tomada = 0, tomadas_recebidas, total_tomada;
  for (int i = 0; i < 4; i++) {
    scanf("%d", &tomadas_recebidas);
    tomada = tomada + tomadas_recebidas;
  }
  total_tomada = tomada - 3;
printf("%d\n", total_tomada);
}
 
