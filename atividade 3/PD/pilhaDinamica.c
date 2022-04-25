#include <stdio.h>
#include <stdlib.h>

struct Iten
{
    int key;
    struct Iten *last;
};

struct Stack
{
    struct Iten *top;
};

struct Stack *createStack();
struct Iten *createIten(int);
int StackEmoty(struct Stack *);
void insertIten(struct Stack *, struct Iten *);
struct Iten *removeIten(struct Stack *);
void viewStack(struct Stack *);

void main()
{
    struct Stack *Stack = createStack();
    struct Iten *it;
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
            it = removeIten(Stack);
            if (it != NULL)
            {
                printf("[%d]\n", it->key);
                free(it);
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
    struct Stack *position = (struct Stack *)malloc(sizeof(struct Stack));
    if (position != NULL)
    {
        position->top = NULL;
    }
    return position;
}

struct Iten *createIten(int key)
{
    struct Iten *it = (struct Iten *)malloc(sizeof(struct Iten));
    if (it != NULL)
    {
        it->key = key;
        it->last = NULL;
    }
    return it;
}

int StackEmoty(struct Stack *position)
{
    return position->top == NULL;
}

void insertIten(struct Stack *position, struct Iten *new)
{
    new->last = position->top;
    position->top = new;
}

struct Iten *removeIten(struct Stack *position)
{
    struct Iten *it = position->top;
    if (!StackEmoty(position)) // if(p->top != NULL) if(it!=NULL)
    {
        position->top = position->top->last;
    }
    return it;
}

void viewStack(struct Stack *position)
{
    struct Iten *it = position->top;
    while (it != NULL)
    {
        printf("%d%s", it->key, it->last != NULL ? " " : "\n");
        it = it->last;
    }
}
