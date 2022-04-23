#include <stdio.h>

struct Iten
{
    int key;
};

struct List
{
    struct Iten *itens;
    int scale, quantity;
};

struct List createList(int);
struct Iten createIten(int);
int fullList(struct List);
int emptyList(struct List);
void insertIten(struct List *, struct Iten);
void removeIten(struct List *, struct Iten);
int getIten(struct List, struct Iten);
void getList(struct List);

int main()
{
    struct List List;
    int n, key;
    char op;
    scanf("%d", &n);
    List = createList(n);
    for (int i = 0; i < n; i++)
    {
        scanf("\n%c", &op);
        if (op == 'I')
        {
            scanf("%d", &key);
            if (getIten(List, createIten(key)) == -1)
            {
                insertIten(&List, createIten(key));
            }
        }
        else
        {
            scanf("%d", &key);
            removeIten(&List, createIten(key));
        }
    }
    getList(List);
}

struct List createList(int n)
{
    struct List l;
    l.quantity = 0;
    l.scale = n;
    l.itens = (struct Iten *)malloc(n * sizeof(struct Iten));
}

struct Iten createIten(int key)
{
    struct Iten it;
    it.key = key;
    return it;
};

int fullList(struct List l)
{
    return l.quantity == l.scale;
}

int emptyList(struct List l)
{
    return l.quantity == 0;
}

void insertIten(struct List *l, struct Iten newIten)
{
    int i, j, aux;
    if (!fullList(*l))
    {
        aux = 0;
        i = 0;
        while (i < l->quantity && !aux)
        {
            if (l->itens[i].key > newIten.key)
            {
                aux = 1;
            }
            else
            {
                i++;
            }
        }
        for (j = l->quantity - 1; j >= i; j--)
        {
            l->itens[j + 1] = l->itens[j];
        }
        l->itens[i] = newIten;
        l->quantity++;
    }
}

void removeIten(struct List *l, struct Iten eliminate)
{
    int i, j;
    if (!emptyList(*l))
    {
        i = getIten(*l, eliminate);
        if (i != 1)
        {
            for (j = i; j < l->quantity; j++)
            {
                l->itens[j] = l->itens[j + 1];
            }
            l->quantity--;
        }
    }
    return i;
}

int getIten(struct List l, struct Iten search)
{
    int start = 0, end = l.quantity - 1, aux;
    while (start <= end)
    {
        aux = (start + end) / 2;
        if (l.itens[aux].key == search.key)
        {
            return aux;
        }
        else if (l.itens[aux].key > search.key)
        {
            end = aux - 1;
        }
        else
        {
            end = aux + 1;
        }
    }
    return -1;
}

void getList(struct List l)
{
    for (int i = 0; i < l.quantity; i++)
    {
        printf("%d\n", l.itens[i].key);
    }
}
