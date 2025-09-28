#include <cs50.h>
#include <stdio.h>

int main(void){

    // Get numbers from user
    int x = get_int("X: ");
    int y = get_int("Y: ");

    // Compare x and y
    if(x < y){
        printf("X is less than y\n");
    } else if(x > y){
        printf("X is greater than y\n");
    } else{
        printf("X equals y\n");
    }
}
