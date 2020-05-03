// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 143007;
unsigned int wordNum = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cur = table[hash(word)];
    while (cur != NULL)
    {
        if (!strcasecmp(cur->word, word))
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // BKDR Hash
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*word)
    {
        // Notice the lower and upper case
        // dereference means get a single char
        hash = hash * seed + tolower((*word++));
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Cannot open %s.\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        ++wordNum;
        node *n = (node *)malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Not enough memory.\n");
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        unsigned int idx = hash(word);
        n->next = table[idx];  // insert at head
        table[idx] = n;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordNum;
}

// Unloads dictionary from memory, returning true if successful else false
// there is no way to test false
bool unload(void)
{
    for (int i = 0; i < N; ++i)
    {
        node *cur = table[i], *tmp = table[i];
        while (cur != NULL)
        {
            cur = cur->next;
            free(tmp);
            tmp = cur;
        }
        table[i] = NULL;
    }
    return true;
}
