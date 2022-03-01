#include <stdio.h>

int main() {
  int cha, tentativa;
  int contador = 0;
  
  scanf("%d", &cha);
  while (cha < 1 || cha > 1000){
    scanf("%d", &cha);
  }

  for (int i = 0; i < 5; i++){
    scanf("%d", &tentativa);
    
    while (tentativa < 1 || tentativa > 1000){
      scanf("%d", &tentativa);
    }
    
    if (tentativa == cha){
      contador ++;
    }
  }
  printf("%d\n", contador);
}
  
