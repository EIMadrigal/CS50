#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = 0;
    for (int i = 0; i < strlen(argv[1]); ++i)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            k = k * 10 + argv[1][i] - '0';
        }
    }
    k %= 26;
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); ++i)
    {
        char c = plain[i];
        if (isupper(c))
        {
            printf("%c", 'A' + (c - 'A' + k) % 26);
        }
        else if (islower(c))
        {
            printf("%c", 'a' + (c - 'a' + k) % 26);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
