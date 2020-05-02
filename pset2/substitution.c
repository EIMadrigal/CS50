#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int cnt[26] = {0};
    bool flag = true;
    for (int i = 0; i < strlen(argv[1]); ++i)
    {
        if (islower(argv[1][i]))
        {
            if (cnt[argv[1][i] - 'a'])
            {
                flag = false;
                break;
            }
            ++cnt[argv[1][i] - 'a'];
        }
        else if (isupper(argv[1][i]))
        {
            if (cnt[argv[1][i] - 'A'])
            {
                flag = false;
                break;
            }
            ++cnt[argv[1][i] - 'A'];
        }
        else
        {
            flag = false;
            break;

        }
    }
    if (!flag)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string input = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(input); ++i)
    {
        if (islower(input[i]))
        {
            input[i] = tolower(argv[1][input[i] - 'a']);
        }
        else if (isupper(input[i]))
        {
            input[i] = toupper(argv[1][input[i] - 'A']);
        }
    }

    printf("%s\n", input);

    return 0;
}
