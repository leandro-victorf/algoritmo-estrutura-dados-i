#include <stdio.h>
#include<string.h>

int main() {
  int n, q;
  scanf("%d", &n);
  char palavras[n][25];
  char tentativa[25];
  int contador = 0;
  
  for (int i = 0; i < n; i++){
    scanf("%s", palavras[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++){
  	scanf("%s", tentativa);
    for (int j = 0; j < n; j++){
      if(strcmp(tentativa, palavras[j]) == 0){
        contador ++;
      }
    }
    printf("%i\n", contador);
    contador = 0;
  }
  return 0;
}
  
