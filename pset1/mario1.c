#include <stdio.h>
#include "cs50.h"

int main(void)
{
    int h = 0;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < h; ++j)
        {
            if (i + j < h - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}
