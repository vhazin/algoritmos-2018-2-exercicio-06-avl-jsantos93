#include <stdio.h>

int main(void)
{
    int t, n, valor;
    int flag = 1;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int arvore[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &valor);
            arvore[i] = valor;
        }
        for (int j = 0; j < n; j++)
        {
            int direita = (2 * j) + 2;
            int esquerda = (2 * j) + 1;

            if (arvore[direita] == -1 && arvore[esquerda] != -1)
            {
                int esquerda_esquerda = (2 * esquerda) + 1;
                int esquerda_direita = (2 * esquerda) + 2;

                if (arvore[esquerda_esquerda] != -1 || arvore[esquerda_direita] != -1)
                {
                    flag = 0;
                    break;
                }
            }
            else if (arvore[esquerda] == -1 && arvore[direita] != -1)
            {
                int direita = (2 * j) + 2;
                int esquerda = (2 * j) + 1;

                if (arvore[direita] == -1 && arvore[esquerda] != -1)
                {
                    int direita_esquerda = (2 * direita) + 1;
                    int direita_direita = (2 * direita) + 2;

                    if (arvore[direita_esquerda] != -1 || arvore[direita_direita] != -1)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
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

    return 0;
}
