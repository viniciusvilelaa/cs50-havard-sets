#include <cs50.h>
#include <stdio.h>
int main(void){
    int size = 0;

    while(size < 1 || size > 8){

        size = get_int("Tamanho: ");

    }

   for(int i = 0; i < size; i++){

    for(int j = 0; j < (size - i); j++){
        printf(" ");

    }
    for(int k = 0; k < i + 1; k++){
         printf("#");
    }

    printf(" ");

    
    for(int k = 0; k < i + 1; k++){
         printf("#");
    }


    printf("\n");
   }




}
