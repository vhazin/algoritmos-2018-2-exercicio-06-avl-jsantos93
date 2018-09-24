#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int getHeight(int a[], int pos, int numeros)
{
    int esq = 2 * pos + 1;
    int dir = 2 * pos + 2;

    if (dir < numeros)
    {
        return a[pos] == -1 ? 0 : 1 + max(getHeight(a, dir, numeros), getHeight(a, esq, numeros));
    }
    if (esq < numeros)
    {
        return a[pos] == -1 ? 0 : 1 + getHeight(a, esq, numeros);
    }

    return a[pos] == -1 ? 0 : 1;
}

int main(void)
{
    int casos, numeros;

    scanf("%d", &casos);

    while (casos--)
    {
        scanf("%d", &numeros);
        int tree[numeros];

        for (int i = 0; i < numeros; i++)
        {
            scanf("%d", &tree[i]);
        }

        int flag = 1;

        for (int j = 1; j < numeros / 2; j += 2)
        {
            int min = getHeight(tree, j, numeros);
            int max = getHeight(tree, j + 1, numeros);

            if (abs(max - min) > 1)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            printf("T\n");
        }
        else
        {
            printf("F\n");
        }
    }
    return 0;
}
