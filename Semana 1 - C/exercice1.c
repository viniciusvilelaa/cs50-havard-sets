#include <stdio.h>
#include <cs50.h>

int main(void){
    int n;
    do{
        n = get_int("Height: ");
    }while(n < 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            printf(" ");

        }
        for(int y = 0; y <= i ; y++){
            printf("#");
        }

        printf("\n");
    }
}
