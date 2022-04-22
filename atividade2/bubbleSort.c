#include <stdio.h>
#include <string.h>

void printVetor(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
}

int main()
{
    int n, chave, contador = 0;
    int vetor[n];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printVetor(vetor, n);
    printf("\n");

    for (int i = 1; i < n; i++)
    {
        chave = vetor[i - 1];
        if (chave > vetor[i])
        {
            vetor[i - 1] = vetor[i];
            vetor[i] = chave;
            printVetor(vetor, n);
            printf("\n");
            contador++;
        }
    }
}
