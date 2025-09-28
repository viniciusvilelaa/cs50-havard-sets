#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Prototype function
string encripty(string word, int key);

int main(int argc, string argv[]){

    // Command-line arguments verification
    if(argc != 2){
        printf("Usage: ./caesar key");
        return 1;
    }else{
        int argvLenght = strlen(argv[1]);
        for(int i = 0; i < argvLenght; i++){
            if(isalpha(argv[1][i])){
                return 1;
            }
        }
    }

    // Convert string to int
    int key = atoi(argv[1]);

    // Getting prompt by user and chipering the text
    string s = get_string("plain-text: ");
    string ciphertext = encripty(s,key);
    printf("ciphertext: %s\n", ciphertext);
    return 0;

}


string encripty(string word, int key){
    string ciphertext = word;
    int n = strlen(word);
    for(int i = 0; i < n; i++){
        if(isalpha(ciphertext[i]) && isupper(ciphertext[i])){
            ciphertext[i] = (ciphertext[i] - 'A' + key) % 26 + 'A';
        }else if(isalpha(ciphertext[i]) && islower(ciphertext[i])){
            ciphertext[i] = (ciphertext[i] - 'a' + key) % 26 + 'a';
        }
    }
    return ciphertext;
}
