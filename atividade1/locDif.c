#include <stdio.h>

int main() {
  int n, t;
  int conti_v = 0;
  int conti_w = 0;
  
  
  
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &t);
    conti_v =conti_v + t;
  }

  for(int i = 0; i <= n; i++){
    scanf("%d", &t);
    conti_w =conti_w + t;
  }
  int resultado = conti_w - conti_v;
  printf("%d\n", resultado);
}

