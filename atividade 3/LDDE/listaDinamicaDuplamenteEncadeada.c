#include <stdio.h>
#include <stdlib.h>

struct Iten
{
    int key;
    struct Iten *before, *next;
};

struct List
{
    struct Iten *first, *last;
};

struct List *createList();
struct Iten *createIten(int);
int emptyList(struct List *);
void insert(struct List *, struct Iten *);
struct Iten *removeIten(struct List *, int);
struct Iten *get(struct List *, int);
void view(struct List *);
void viewTopDown(struct List *);

void main()
{
    struct List *List = createList();
    struct Iten *it;
    int key;
    char op;

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &key);
            insert(List, createIten(key));
        }
        else if (op == 'E')
        {
            scanf("%d", &key);
            it = removeIten(List, key);
            if (it != NULL)
            {
                free(it);
            }
        }
        else if (op == 'M')
        {
            view(List);
        }
        else
        {
            viewTopDown(List);
        }
    }
}

struct List *createList()
{
    struct List *l = (struct List *)malloc(sizeof(struct List));

    if (l != NULL)
    {
        l->first = NULL;
        l->last = NULL;
    }
    return l;
}

struct Iten *createIten(int key)
{
    struct Iten *it = (struct Iten *)malloc(sizeof(struct Iten));

    if (it != NULL)
    {
        it->key = key;
        it->before = NULL;
        it->next = NULL;
    }
    return it;
}

int emptyList(struct List *l)
{
    return l->first == NULL && l->last == NULL;
}

void insert(struct List *l, struct Iten *novo)
{
    struct Iten *atual = l->first;

    while (atual != NULL && atual->key < novo->key)
    {
        atual = atual->next;
    }

    if (atual != NULL)
    {
        novo->before = atual->before;
        novo->next = atual;

        if (atual->before != NULL)
        {
            atual->before->next = novo;
        }
        else
        {
            l->first = novo;
        }
        atual->before = novo;
    }
    else if (emptyList(l))
    {
        l->first = novo;
        l->last = novo;
    }
    else
    {
        l->last->next = novo;
        novo->before = l->last;
        l->last = novo;
    }
}

struct Iten *removeIten(struct List *l, int key)
{
    struct Iten *atual = get(l, key);

    if (atual != NULL)
    {
        if (atual->before != NULL)
        {
            if (atual->next != NULL)
            {
                atual->before->next = atual->next;
                atual->next->before = atual->before;
            }
            else
            {
                atual->before->next = atual->next;
                l->last = atual->before;
            }
        }
        else
        {
            atual->next->before = atual->before;
            l->first = atual->next;
        }
    }
    return atual;
}

struct Iten *get(struct List *l, int key)
{
    struct Iten *it = l->first;

    while (it != NULL && it->key < key)
    {
        it = it->next;
    }

    if (it != NULL && it->key != key)
    {
        it = NULL;
    }
    return it;
}

void view(struct List *l)
{
    struct Iten *it = l->first;

    while (it != NULL)
    {
        printf("%d%s", it->key, it->next != NULL ? " " : "\n");
        it = it->next;
    }
}

void viewTopDown(struct List *l)
{
    struct Iten *it = l->last;

    while (it != NULL)
    {
        printf("%d%s", it->key, it->before != NULL ? " " : "\n");
        it = it->before;
    }
}