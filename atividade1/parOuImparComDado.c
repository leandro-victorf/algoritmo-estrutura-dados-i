#include <stdio.h>

int pontuacao (int dado, int pontos){
    if ( (dado % 2) == (pontos % 2)){
      return 1;
    }else{
      if (pontos == 0){
        return 0;
      }else {
        return -1;
      }
    }
  }

int main() {
  int n, s, a, b;
  int jogador = 1;
  int pontos_um = 0;
  int pontos_dois = 0;
  
  scanf("%d", &n);

  do{
    scanf("%d", &s);
    if (jogador % 2 == 1){
      pontos_um += pontuacao(s, pontos_um);
    }else{
      pontos_dois += pontuacao(s, pontos_dois);
    }
    jogador++;
    a = pontos_um;
    b= pontos_dois;
  }while(a != n & b != n);
  if(pontos_um == n){
    printf("Sheldon\n");
  }else{
    printf("Leonard\n");
  }
}

