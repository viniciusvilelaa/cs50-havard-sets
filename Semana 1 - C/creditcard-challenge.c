#include <stdio.h>
#include <cs50.h>
#include <math.h>

// 4 VISA
// 34 OU 37 AMEX
// 51,52,53,54 OU 55 MASTER

bool totalOfDigits(long cardNumber){
    int total = 0;
    while (cardNumber > 0)
    {
        cardNumber /= 10;
        total++;
    }
    if(total < 13 || total > 16){
        return false;
    }else{
        return true;
    }
}

bool checksum(long cardNumber){

    int sum = 0;
    int position = 0;

    while(cardNumber > 0){

        int digit = cardNumber % 10;

        if(position % 2 == 1){
            int doubled = digit * 2;
            sum += doubled / 10 + doubled % 10;
        }else{
            sum += digit;
        }

        cardNumber /= 10;
        position++;

    }

    return (sum % 10 == 0);




}








int main(void){

    long cardNumber = get_long("Credit card number: ");

    if(totalOfDigits(cardNumber) == true){
            if(checksum(cardNumber) == true){
                while(cardNumber >= 100){
                cardNumber /= 10;
                }
                if(cardNumber >= 40 && cardNumber < 50){
                printf("VISA\n");
                }else if(cardNumber > 50 && cardNumber < 56 ){
                printf("MASTER\n");
                }else if(cardNumber == 34 || cardNumber == 37){
                printf("AMEX\n");
                }else {
                printf("Invalid initial digit of card\n");
                }
            }

    }else{
            printf("Invalid lenght of card\n");
        }
}
