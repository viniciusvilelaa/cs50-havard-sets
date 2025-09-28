#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int number;
    struct node *left;
    struct node *right;
}
node;

bool search(node *tree, int number);

int main(void){
    node *list = NULL;
    node *n = malloc(sizeof(node));
    if(n == NULL){
        return 1;
    }

    n->number = 4;
    n->left = NULL;
    n->right = NULL;
    list = n;

    n = malloc(sizeof(node));
    if(n == NULL){
        free(list);
        return 1;
    }

    n->number = 6;
    n->right = NULL;
    n->left = NULL;
    list->right = n;

    search(list, 6);

    free(list);
    free(n);


}

bool search(node *tree, int number){

    if(tree == NULL){
        return false;
    }else if(number < tree->number){
        search(tree->left, number);
    }  else if(number > tree->number)
    {
        search(tree->right, number);

    }else
    {
        printf("achei\n");
        return true;
    }

    return false;
}
