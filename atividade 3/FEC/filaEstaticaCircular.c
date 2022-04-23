#include <stdio.h>
#include <stdlib.h>

struct Iten
{
    int key;
};

struct RoundStaticRow
{
    struct Iten *itens;
    int scale;
    int start, end;
};

struct RoundStaticRow createRoundStaticRow(int);
struct Iten creatIten(int);
void insertiIten(struct RoundStaticRow *, struct Iten);
struct Iten removeIten(struct RoundStaticRow *);
int empryRoundRow(struct RoundStaticRow);
int fullRoundRow(struct RoundStaticRow);

int main()
{
    struct RoundStaticRow row;
    int n, key;
    char op;

    scanf("%d", &n);
    row = createRoundStaticRow(n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &key);
            insertiIten(&row, creatIten(key));
        }
        else
        {
            if (!empryRoundRow(row))
            {
                printf("%d\n", removeIten(&row).key);
            }
        }
    }

    return 0;
}

struct RoundStaticRow createRoundStaticRow(int n)
{
    struct RoundStaticRow f;
    f.itens = (struct Iten *)malloc(n * sizeof(struct Iten));
    f.scale = n;
    f.start = 0;
    f.end = 0;
    return f;
}

struct Iten creatIten(int key)
{
    struct Iten it;
    it.key = key;
    return it;
}

void insertiIten(struct RoundStaticRow *f, struct Iten newIten)
{
    if (!fullRoundRow(*f))
    {
        f->itens[f->end] = newIten;
        f->end = (f->end + 1) % f->scale;
    }
}

struct Iten removeIten(struct RoundStaticRow *f)
{
    struct Iten it;
    if (!empryRoundRow(*f))
    {
        it = f->itens[f->start];
        f->start = (f->start + 1) % f->scale;
    }
    return it;
}

int empryRoundRow(struct RoundStaticRow f)
{
    return f.start == f.end;
}

int fullRoundRow(struct RoundStaticRow f)
{
    return (f.end + 1) % f.scale == f.start;
}
