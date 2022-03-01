#include <stdio.h>

int main() {
  int vetor_maior[3];
  int auxiliar = (1LL<<(sizeof(typeof(auxiliar))*8-1));
  for ( int i = 0; i < 3; i++ ) {
        scanf ( "%d", &vetor_maior[i] );
    }

  for(int i = 0; i < 3; i++){
    if (vetor_maior[i] >= auxiliar){
      auxiliar = vetor_maior[i];
    }
  }
   printf("%d eh o maior.\n", auxiliar);
}
  
