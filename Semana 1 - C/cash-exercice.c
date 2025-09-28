#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float cash;
    // Get number from user
    do{
        cash = get_float("Change owed: ");
    }while(cash < 0);

    // Transform float in int
    int cash_regularized = round(cash*100);

    // Variable for total coins used
    int totalCoins = 0;

   do{
    if(cash_regularized >= 25){
        cash_regularized = cash_regularized - 25;
        totalCoins++;
    }else if(cash_regularized < 25 && cash_regularized >= 10){
        cash_regularized = cash_regularized - 10;
        totalCoins++;
    }else if(cash_regularized < 10 && cash_regularized >= 5){
        cash_regularized = cash_regularized - 5;
        totalCoins++;
    }else{
        cash_regularized = cash_regularized - 1;
        totalCoins++;
    }
   }while(cash_regularized > 0);

   printf("%i", totalCoins);
   printf("\n");
}
