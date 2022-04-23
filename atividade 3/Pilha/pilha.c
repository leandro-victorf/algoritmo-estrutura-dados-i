#include <stdio.h>
#include <stdlib.h>

struct Iten
{
    int key;
};

struct StaticStack
{
    struct Iten *itens;
    int scale;
    int top;
};

struct StaticStack createStaticStack(int);
struct Iten createIten(int);
int emptystack(struct StaticStack);
int fullStack(struct StaticStack);
struct Iten removeIten(struct StaticStack *);
void insertIten(struct StaticStack *, struct Iten);
void getTopDown(struct StaticStack);
void getDownTop(struct StaticStack);

int main()
{
    struct StaticStack satck;
    int n, key;
    char op;

    scanf("%d", &n);
    satck = createStaticStack(n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &key);
            insertIten(&satck, createIten(key));
        }
        else if (op == 'D')
        {
            if (!emptystack(satck))
            {
                removeIten(&satck).key;
            }
        }
        else if (op == 'T')
        {
            getTopDown(satck);
        }
        else
        {
            getDownTop(satck);
        }
    }
    free(satck.itens);
    return 0;
}

struct StaticStack createStaticStack(int n)
{
    struct StaticStack element;
    element.itens = (struct Iten *)malloc(n * sizeof(struct Iten));
    element.scale = n;
    element.top = -1;
    return element;
}

struct Iten createIten(int key)
{
    struct Iten it;
    it.key = key;
    return it;
}

int emptystack(struct StaticStack element)
{
    return element.top == -1;
}

int fullStack(struct StaticStack element)
{
    return element.top == element.scale - 1;
}

void insertIten(struct StaticStack *element, struct Iten novo)
{
    if (!fullStack(*element))
    {
        element->top++;
        element->itens[element->top] = novo;
    }
}

struct Iten removeIten(struct StaticStack *element)
{
    struct Iten it;
    if (!emptystack(*element))
    {
        it = element->itens[element->top];
        element->top--;
    }
    return it;
}

void getDownTop(struct StaticStack element)
{
    int i;
    for (i = 0; i <= element.top; i++)
    {
        printf("%d\n", element.itens[i].key);
    }
}

void getTopDown(struct StaticStack element)
{
    int i;
    for (i = element.top; i >= 0; i--)
    {
        printf("%d\n", element.itens[i].key);
    }
}