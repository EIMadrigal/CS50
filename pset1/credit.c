#include <stdio.h>
#include "cs50.h"

struct card
{
    int n[20];
    int len;
};

int main(void)
{
    long num = get_long("Number: ");
    int candidate = 0;
    struct card c;
    c.len = 0;
    
    while(num)
    {
        c.n[c.len++] = num % 10;
        num /= 10;
    }

    if (c.len == 15 && c.n[14] == 3 && (c.n[13] == 4 || c.n[13] == 7))
    {
        candidate = 1;
    }
    else if (c.len == 16 && c.n[15] == 5 && (c.n[14] == 1 || c.n[14] == 2 || c.n[14] == 3 ||c.n[14] == 4 ||c.n[14] == 5))
    {
        candidate = 2;
    }
    else if(num / 10000000000000 == 4 || num / 1000000000000000 == 4)
    {
        candidate = 3;
    }

    

    if (candidate)
    {
        int sum = 0;
        for(int i = 0; i < c.len; ++i)
        {
            if(i & 1)
            {
                if(c.n[i] >= 5)
                {
                    int tmp = c.n[i] * 2;
                    sum += tmp % 10;
                    sum += 1;
                }
                else
                {
                    sum += c.n[i] * 2;
                }
            }
            else
            {
                sum += c.n[i];
            }
        }
        if(sum % 10 == 0)
        {
            switch(candidate)
            {
                case 1: printf("AMEX\n"); break;
                case 2: printf("MASTERCARD\n"); break;
                case 3: printf("VISA\n"); break;
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
