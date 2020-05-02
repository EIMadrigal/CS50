#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; ++i)
    {
        // check the boundray
        for (int j = 1; j <= n + i + 2; ++j)
        {
            // check the two parts
            if ((j >= n + 1 - i && j >= 1 && j <= n) || (j >= n + 3 && j <= 2 * n + 2 && j <= i + n + 2))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
