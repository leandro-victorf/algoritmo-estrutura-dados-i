#include <stdio.h>
#include <stdlib.h>

struct Iten
{
    int key;
};

struct StaticRow
{
    struct Iten *itens;
    int scale;
    int start, end;
};

struct StaticRow createStaticaRow(int);
struct Iten createIten(int);
void insertIten(struct StaticRow *, struct Iten);
struct Iten removeIten(struct StaticRow *);
int emptyRow(struct StaticRow);
int fullRow(struct StaticRow);
// void getRow(struct StaticRow);

int main()
{
    struct StaticRow fila;
    int n, key;
    char op;

    scanf("%d", &n);
    fila = createStaticaRow(n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &key);
            insertIten(&fila, createIten(key));
        }
        else
        {
            if (!emptyRow(fila))
            {
                printf("%d\n", removeIten(&fila).key);
            }
        }
        // getRow(fila);
    }

    return 0;
}

struct StaticRow createStaticaRow(int n)
{
    struct StaticRow f;
    f.itens = (struct Iten *)malloc(n * sizeof(struct Iten));
    f.scale = n;
    f.start = -1;
    f.end = -1;
    return f;
}

struct Iten createIten(int key)
{
    struct Iten it;
    it.key = key;
    return it;
}

void insertIten(struct StaticRow *f, struct Iten novo)
{
    if (!fullRow(*f))
    {
        if (emptyRow(*f))
        {
            f->start++;
        }
        f->end++;
        f->itens[f->end] = novo;
    }
}

struct Iten removeIten(struct StaticRow *f)
{
    struct Iten it;
    if (!emptyRow(*f))
    {
        it = f->itens[f->start];
        if (f->start != f->end)
        {
            f->start++;
        }
        else
        {
            f->start = -1;
            f->end = -1;
        }
    }
    return it;
}

int emptyRow(struct StaticRow f)
{
    return f.start == -1 && f.end == -1 || f.start > f.end;
}

int fullRow(struct StaticRow f)
{
    return f.end == f.scale - 1;
}

// void getRow(struct StaticRow f)
// {
//     int i;
//     if (!emptyRow(f))
//     {
//         for (i = f.start; i <= f.end; i++)
//         {
//             printf("%d%s", f.itens[i].key, i < f.end ? " " : "\n");
//         }
//     }
// }