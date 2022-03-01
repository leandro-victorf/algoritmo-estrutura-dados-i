#include <stdio.h>

int main() {
  int tempo, peca_um, peca_dois;
  
  scanf("%d", &tempo);
  while (tempo < 1 || tempo > 1000){
    scanf("%d", &tempo);
  }

  scanf("%d", &peca_um);
  while (peca_um < 1 || peca_um > 1000){
    scanf("%d", &peca_um);
  }

  scanf("%d", &peca_dois);
  while (peca_dois < 1 || peca_dois > 1000){
    scanf("%d", &peca_dois);
  }

  if ((peca_um + peca_dois) > tempo){
    printf("Deixa para amanha!\n");
  } else{
    printf("Farei hoje!\n");
  }
}
  
