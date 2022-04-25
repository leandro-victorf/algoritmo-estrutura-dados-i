#include <stdio.h>
#include <stdlib.h>

struct Iten
{
    int key;
    struct Iten *next;
};

struct List
{
    struct Iten *start;
};

struct List *createList();
struct Iten *createIten(int);
void insert(struct List *, struct Iten *);
struct Iten *removeIten(struct List *, int);
struct Iten *get(struct List *, int);
void view(struct List *);

void main()
{
    struct List *list = createList();
    struct Iten *it;
    int key;
    char op;

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &key);
            if (get(list, key) == NULL)
            {
                insert(list, createIten(key));
            }
        }
        else if (op == 'R')
        {
            scanf("%d", &key);
            it = removeIten(list, key);
            if (it != NULL)
            {
                free(it);
            }
        }
        else if (op == 'B')
        {
            scanf("%d", &key);
            if (get(list, key) == NULL)
            {
                printf("NAO\n");
            }
            else
            {
                printf("SIM\n");
            }
        }
        else
        {
            view(list);
        }
    }
}

struct List *createList()
{
    struct List *l = (struct List *)malloc(sizeof(struct List));
    if (l != NULL)
    {
        l->start = NULL;
    }
    return l;
}

struct Iten *createIten(int key)
{
    struct Iten *it = (struct Iten *)malloc(sizeof(struct Iten));
    if (it != NULL)
    {
        it->key = key;
        it->next = NULL;
    }
    return it;
}

void insert(struct List *l, struct Iten *novo)
{
    struct Iten *last = NULL, *now = l->start;
    int achei = 0;

    while (now != NULL && !achei)
    {
        if (now->key > novo->key)
        {
            achei = 1;
        }
        else
        {
            last = now;
            now = now->next;
        }
    }

    if (last == NULL)
    {
        l->start = novo;
    }
    else
    {
        last->next = novo;
    }
    novo->next = now;
}
struct Iten *removeIten(struct List *l, int key)
{
    struct Iten *last = NULL, *now = l->start;

    while (now != NULL && now->key < key)
    {
        last = now;
        now = now->next;
    }

    if (now != NULL)
    {
        if (now->key == key)
        {
            if (last == NULL)
            {
                l->start = now->next;
            }
            else
            {
                last->next = now->next;
            }
        }
        else
        {
            now = NULL;
        }
    }
    return now;
}

struct Iten *get(struct List *l, int key)
{
    struct Iten *it = l->start;
    while (it != NULL && it->key < key)
    {
        it = it->next;
    }

    if (it != NULL)
    {
        if (it->key == key)
        {
            return it;
        }
    }
    return NULL;
}

void view(struct List *l)
{
    struct Iten *it = l->start;
    while (it != NULL)
    {
        printf("%d%s", it->key, it->next != NULL ? " " : "\n");
        it = it->next;
    }
}
