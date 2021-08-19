// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

unsigned int index_value;     // The hash result
unsigned int counter;   // Keep track of nodes
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    index_value = hash(word);
    node *cursor = table[index_value];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
            return true;
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // djb2 algorithm
    unsigned long hash = 5381;
    int i;
    while ((i = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + i;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open file and check if is valid
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // Read lines from dict and alloc memory for them
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node)); // Valgrind said there 112 bytes reachable, not a problem tho
        if (n == NULL)
        {
            return false;
        }

    // Copy words to nodes
    strcpy(n->word, word);
    index_value = hash(word);
    table[index_value] = n;
    counter++;
    }
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return (counter > 0) ? counter : 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        if (cursor == NULL)
            return true;

        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
