#include <stdio.h>

int main()
{
    int n, contador = 0;
    int vetor[n];
    scanf("%d", &n);

    if (n == 0)
    {
        printf("S\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vetor[i]);
        }

        for (int i = 1; i < n; i++)
        {
            if (vetor[i - 1] > vetor[i])
            {
                contador++;
            }
        }

        if (contador == 0)
        {
            printf("S\n");
        }
        else
        {
            printf("N\n");
        }
    }
}
