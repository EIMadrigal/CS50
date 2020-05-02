#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cs50.h"

int countLetter(string s);
int countWord(string s);
int countSentence(string s);

int main(void)
{
    string input = get_string("Text: ");

    int cntLetter = countLetter(input);
    int cntWord = countWord(input);
    int cntSentence = countSentence(input);
    float L = 100.0 * cntLetter / cntWord;
    float S = 100.0 * cntSentence / cntWord;
    int idx = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5);
    if (idx >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (idx < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", idx);
    }
}

int countLetter(string s)
{
    int cnt = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (islower(s[i]) || isupper(s[i]))
        {
            ++cnt;
        }
    }
    return cnt;
}

int countWord(string s)
{
    int cnt = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == ' ')
        {
            ++cnt;
        }
    }
    return cnt + 1;
}


int countSentence(string s)
{
    int cnt = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            ++cnt;
        }
    }
    return cnt;
}
