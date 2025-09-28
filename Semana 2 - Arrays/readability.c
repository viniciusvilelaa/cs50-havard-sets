#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int compute_letters(string s);
int compute_words(string s);
int compute_sentences(string s);

int main(void){

    string s = get_string("Text: ");
    int letters = compute_letters(s);
    int words = compute_words(s);
    int sentences = compute_sentences(s);
    float L = letters /  (float) words * 100;

    float S = (sentences / (float) words) * 100;

    float indice = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) round(indice);

    if(grade < 1){
        printf("Before Grade 1\n");
    }else if (grade > 16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %i\n", grade);
    }




}

// Count the sentences
int compute_sentences(string s){
    int n = strlen(s);
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.' || s[i] == '!' || s[i] == '?'){
            sum += 1;
        }
    }
    return sum;
}

// Count the letters
int compute_letters(string s){
    int n = strlen(s);
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(isalpha(s[i])){
            sum += 1;
        }
    }
    return sum;
}

// Count the words
int compute_words(string s){
    int n = strlen(s);
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(isalpha(s[i-1]) && isspace(s[i])){
            sum += 1;
        }else if(isalpha(s[i-1]) && s[i] == '.'){
            sum += 1;
        }else if(isalpha(s[i-1]) && s[i] == ','){
            sum += 1;
        }else if(isalpha(s[i-1]) && s[i] == '!'){
            sum += 1;
        }else if(isalpha(s[i-1]) && s[i] == '?'){
            sum += 1;
        }
    }
    return sum;
}
