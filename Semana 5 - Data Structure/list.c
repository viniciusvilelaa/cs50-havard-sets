#include <stdio.h>
#include <stdlib.h>


int main(void){
    //Alocate a chunk of memory for 3 integers
    int *list = malloc(3 * sizeof(int));

    //Verify if list really have space for the data
    if(list == NULL)
    {
        return 1;
    }

    //Set integers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //Alocate chunk of memory for 4 intergers
    int *tmp = realloc(list, 4 * sizeof(int));

    //Verify if temp really have space for the data
    if(tmp == NULL)
    {
        free(list);
        return 1;
    }


    //Add new data to temp
    tmp[3] = 4;

    //Exclude older list
    free(list);

    //Copy temp to list
    list = tmp;

    //Print each element of new list
    for(int i = 0; i < 4; i++){
        printf("%i\n", list[i]);
    }

    free(list);

}
