#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int initialPopulation;
    int finalPopulation;
    int actualPopulation;
    int years = 0;
    do{
        initialPopulation = get_int("Initial population: ");
    }while(initialPopulation < 9);

    do{
        finalPopulation = get_int("Final population: ");
    }while(finalPopulation < initialPopulation);

    actualPopulation = initialPopulation;
    //lhams/3 nascem
    //lhams/4 morrem

    while(actualPopulation < finalPopulation){
        int born = actualPopulation / 3;
        int die = actualPopulation / 4;
        actualPopulation = actualPopulation + born - die;
        years++;
    }
    printf("Years: %i\n", years);


}
