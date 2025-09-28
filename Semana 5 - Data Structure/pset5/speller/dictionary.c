// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    if(table[index] == NULL){
        return false;
    }
    for(node *tmp = table[index]; tmp != NULL; tmp = tmp->next){
        if(strcasecmp(word, tmp->word) == 0){
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if(strlen(word) == 1)
    {
        return toupper(word[0]) - 'A';
    }

    return ((toupper(word[0]) - 'A') * 26 + (toupper(word[1]) - 'A')) % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if(file == NULL){
        return false;
    }

    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            printf("Not hable to alocate memory for node");

            return false;
        }

        strcpy(n->word, word);

        int index = hash(word);

        n->next = table[index];
        table[index] = n;


    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    // TODO
    for(int i = 0; i < N; i++){
        for(node *tmp = table[i]; tmp != NULL; tmp = tmp->next){
            count++;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++){
        node *tmp = table[i];
        while(tmp != NULL){
            node *next = tmp->next;
            free(tmp);
            tmp = next;
        }
    }
    return true;
}
