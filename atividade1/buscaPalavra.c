#include <stdio.h>
#include<string.h>

int main() {
  int n, q;
  scanf("%d", &n);
  char palavras[25][25];
  char tentativas[25][25];
  int contador = 0;
  
  for (int i = 0; i < n; i++){
    scanf("%s", palavras[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++){
    scanf("%s", tentativas[i]);
  }

  for (int i = 0; i < q; i++){
    for (int j = 0; j < n; j++){
      if (strcmp(tentativas[i], palavras[j]) == 0){
        contador++;
      }
    }
    printf("%i\n", contador);
    contador = 0;
  }
}
  
