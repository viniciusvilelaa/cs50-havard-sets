#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Solicitar ao usuário duas palavras
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calcular os pontos de cada palavra
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 == score2){
        printf("Tie\n");
    }else if(score1 > score2){
        printf("Player 1 wins!\n");
    }else if(score2 > score1){
        printf("Player 2 wins!\n");
    }
    // Imprimir o vencedor
}

int compute_score(string word)
{
    int n = strlen(word);
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(isalpha(word[i])){
            int index = toupper(word[i]) - 'A';
            sum += POINTS[index];
        }else{
            sum += 1;
        }
    }
    return sum;
}
