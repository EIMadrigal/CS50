#include <stdio.h>
#include <math.h>
#include "cs50.h"

int main(void)
{
    float f = 0.0;
    do
    {
        f = get_float("Change owed: ");
    }
    while (f < 0);

    int cents = round(100 * f);
    int cnt = 0;
    int s[4] = {25, 10, 5, 1};
    while (cents)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (cents >= s[i])
            {
                cents -= s[i];
                ++cnt;
                break;
            }
        }
    }
    printf("%d\n", cnt);

    return 0;
}
