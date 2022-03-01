#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  int i;
  char letra, letra_minuscula;
  char alfabeto[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  scanf("%s", &letra);
  letra_minuscula = tolower(letra);
  int posicao;
  for (i = 0; i < 26; i++) {
    if (letra_minuscula == alfabeto[i]){
      posicao = i+1;
    }
  }
printf("%d\n", posicao);
}
  
