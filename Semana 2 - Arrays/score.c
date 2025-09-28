#include <stdio.h>
#include <cs50.h>

const int TOTAL = 3;
float avarage(void);

int main(void){
    //int total = get_int("Total number of scores: ");
    // Array of scores
    int scores[TOTAL];

    //Getting scores from user
    for(int i = 0; i < TOTAL; i++){
        scores[i] = get_int("Score: ");
    }

    printf("Avarage: %.3f\n", avarage(TOTAL, scores);
}

//Calculate avarage
float avarage(int length, int array[]){
    int sum = 0;

    for(int i = 0; i < length; i++){
        sum += array[i]
    }



    return sum / (float) length;
}
