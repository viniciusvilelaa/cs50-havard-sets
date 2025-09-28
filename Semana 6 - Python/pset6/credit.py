import cs50
import sys
import re

#Function for check the Luhn number
def checksum(cardNumber):
    multiples = []
    soma = 0

    #Create array with multiplied numbers by 2
    for multiple in range(len(cardNumber) - 2, -1, -2):
        multiples.append(int(cardNumber[multiple]) * 2)

    #Add theese number to sum count
    for i in multiples:
        soma += i // 10 + i % 10
    #Add no multiplied numbers to sum
    for nomultiples in range(len(cardNumber) -1, -1, -2):
            soma += int(cardNumber[nomultiples])

    #Verify if sum is valid for luhn algorithm
    return soma % 10 == 0


def main():
    #User card number input
    cardNumber = cs50.get_string("Credit card number: ")
    #Set pattern for card number verification
    pattern = r"^\d{13,16}$"

    #Verify if card number is in pattern
    if not re.match(pattern, cardNumber) :
        print("INVALID")
        sys.exit(1)

    #Call checksum function, if returns false stop the program
    if not checksum(cardNumber):
        print("INVALID")
        sys.exit(1)

    #Set variable for two first digits of card number
    firstDigits = int(cardNumber[0] + cardNumber[1])

    #Verify which brand it's
    if firstDigits in (34, 37):
        print("AMEX")
    elif  51<= firstDigits <= 55:
        print("MASTERCARD")
    elif 40 <= firstDigits <=49:
        print("VISA")
    else:
        print("INVALID")
        sys.exit(1)


main()

