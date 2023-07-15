// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

void freespace(node *curser);
// TODO: Choose number of buckets in hash table
const unsigned int N = 5000;
unsigned int COUNT = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);
    node *cursur = table[index];
    while (cursur != NULL)
    {
        if (strcasecmp(word, (cursur->word)) == 0)
        {
            return true;
        }
        cursur = cursur -> next;
    }
    return false;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
     unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fclose(file);
        return false;
    }

    char buffer[LENGTH + 1];

   
  for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            fclose(file);
            return false;
        }

        int index = hash(buffer);

        strcpy((n->word), buffer);
        n->next = NULL;

        if ((table[index]) != NULL)
        {
            node *tmp = (table[index]);
            n -> next = tmp;
            table[index] = n;
        }
        else
        {
            table[index] = n;
        }

        COUNT++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return COUNT;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        node *temp = n;

        //Loop through linked list
        while (n != NULL)
        {
            // n -> 2nd closest linked list
            n = n-> next;
            // temp -> closest linked list(free)
            free(temp);
            // n & temp -> 2nd closest linked list
            temp = n;
        }
    }
    return true;
}

