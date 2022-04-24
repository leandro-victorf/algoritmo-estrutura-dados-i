#include <stdio.h>
#include <stdlib.h>

struct Iten
{
    int key;
    struct Iten *next;
};

struct Stack
{
    struct Iten *start;
    struct Iten *finish;
};

struct Stack *createStack();
struct Iten *createIten(int);
int StackEmpty(struct Stack *);
void insertIten(struct Stack *, struct Iten *);
struct Iten *removeIten(struct Stack *);
void viewStack(struct Stack *);

void main()
{
    struct Stack *Stack = createStack();
    struct Iten *thisIten;
    int key;
    char op;
    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &key);
            insertIten(Stack, createIten(key));
        }
        else if (op == 'D')
        {
            thisIten = removeIten(Stack);
            if (thisIten != NULL)
            {
                printf("<%d>\n", thisIten->key);
                free(thisIten);
            }
        }
        else
        {
            viewStack(Stack);
        }
    }
}

struct Stack *createStack()
{
    struct Stack *thisFila = (struct Stack *)malloc(sizeof(struct Stack));
    if (thisFila != NULL)
    {
        thisFila->start = NULL;
        thisFila->finish = NULL;
    }
    return thisFila;
}

struct Iten *createIten(int key)
{
    struct Iten *thisIten = (struct Iten *)malloc(sizeof(struct Iten));
    if (thisIten != NULL)
    {
        thisIten->key = key;
        thisIten->next = NULL;
    }
    return thisIten;
}

int StackEmpty(struct Stack *thisFila)
{
    return thisFila->start == NULL && thisFila->finish == NULL;
}

void insertIten(struct Stack *thisFila, struct Iten *newIten)
{
    if (StackEmpty(thisFila))
    {
        thisFila->start = newIten;
    }
    else
    {
        thisFila->finish->next = newIten;
    }
    thisFila->finish = newIten;
}

struct Iten *removeIten(struct Stack *thisFila)
{
    struct Iten *thisIten = thisFila->start;
    if (!StackEmpty(thisFila))
    {
        thisFila->start = thisFila->start->next;
        if (thisFila->start == NULL)
        {
            thisFila->finish = NULL;
        }
    }
    return thisIten;
}
void viewStack(struct Stack *thisFila)
{
    struct Iten *thisIten = thisFila->start;
    while (thisIten != NULL)
    {
        printf("%d%s", thisIten->key, thisIten->next != NULL ? " " : "\n");
        thisIten = thisIten->next;
    }
}