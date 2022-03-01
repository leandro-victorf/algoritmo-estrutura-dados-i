#include <stdio.h>

int main() {
  int area, estrelas, frequencia;
  int contador = 0;
  
  scanf("%d", & area);
  scanf("%d", &estrelas);

  for (int i = 0; i < estrelas; i++){
    scanf("%d", &frequencia);
    float visivel = area * frequencia / 40000000;
    if (visivel >= 1){
      contador++;
    }
  }

  printf("%d\n", contador);
}
  
