#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

string substitution(string plaintext, string key);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./substitution key of substitution\n");
        return 1;
    }else if(strlen(argv[1]) != 26){
        printf("The key must contain 26 characters\n");
        return 1;
    }
    int n = strlen(argv[1]);
    for(int i = 0; i < n; i++){
        if(!isalpha(argv[1][i])){
            printf("Usage: ./substitution key of substitution\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
        if (toupper(argv[1][i]) == toupper(argv[1][j])){
            printf("The key must not contain repeated characters\n");
            return 1;
        }
    }
}


    string key = argv[1];

    string plaintext = get_string("plaintext: ");
    string substitutionText = substitution(plaintext, key);
    printf("ciphertext: %s\n", substitutionText);
    free(substitutionText);
    return 0;
}

string substitution(string plaintext, string key){

    int arrayLength = strlen(plaintext);
    char* ciphertext = malloc(arrayLenght + 1);
    for(int i = 0; i < arrayLength; i++){
        if(isalpha(plaintext[i])){
            if(isupper(plaintext[i])){
            int charPosition = plaintext[i] - 'A';
            ciphertext[i] = toupper(key[charPosition]);
            }else if(islower(plaintext[i])){
                int charPosition = plaintext[i] - 'a';
                ciphertext[i] = tolower(key[charPosition]);
            }
        }else{
            ciphertext[i] = plaintext[i];
        }

    }


    return ciphertext;
}
