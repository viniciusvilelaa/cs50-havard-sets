#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    // Pecorre array de candidatos
    for(int i = 0; i < candidate_count; i++){

        // Verifica se o candidato é aquele que o eleitor escolheu
        if(strcmp(candidates[i], name) == 0){

            // Atualiza array ranks[] e retorna true
            ranks[rank] = i;
            return true;
        }

    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // Loop para definir primeiro candidato a vir na preferences
    for(int i = 0; i < candidate_count - 1 ; i++){

        // Loop para definir primeiro candidato a vir na preferences
        for(int j = i+1; j < candidate_count; j++){
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int pair_number = 0;

    for(int i = 0; i < candidate_count; i++){
        for(int j = i+1; j < candidate_count; j++){
            if(preferences[i][j] > preferences[j][i]){
                pairs[pair_number].winner = i;
                pairs[pair_number].loser = j;

                pair_number++;
            }else if(preferences[j][i] > preferences[i][j]){
                pairs[pair_number].winner = j;
                pairs[pair_number].loser = i;

                pair_number++;
            }
        }

        pair_count = pair_number;

    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO

    // Seleciona um candidato i a cada iteração
    for(int i = 0; i < pair_count - 1; i++){

        // Seleciona um candidato j a cada iteração
        for(int j = i + 1; j < pair_count; j++){

            // Define em duas variaveis sua força de vitória para cada dupla
            int strength_i = preferences[pairs[i].winner][pairs[i].loser];
            int max_strength = preferences[pairs[j].winner][pairs[j].loser];

            // Encontra quem é o par com maior força e define o indice dele j como max_index
            if(strength_i < max_strength){
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }

        }
        // Salva temporariamente o par[i]
        pair temp = pairs[i];

        // Faz o swap


    }
    return;
}

bool has_cycle(int winner, int loser){
    if(loser == winner){
        return true;
    }

    for(int i = 0; i < candidate_count; i++){
        if(locked[loser][i]){
            if(has_cycle(winner, i)){
                return true;
            }
        }
    }

    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for(int i = 0; i < pair_count; i++){

        if(!has_cycle(pairs[i].winner, pairs[i].loser)){
            locked[pairs[i].winner][pairs[i].loser] = true;
        }

    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for(int i = 0; i < candidate_count; i++){
        bool winner = true;
        for(int j = 0; j < candidate_count; j++){
            if(locked[j][i]){
                winner = false;
                break;
            }

        }
        if(winner){
                printf("%s\n", candidates[i]);
                return;
            }
    }
}
