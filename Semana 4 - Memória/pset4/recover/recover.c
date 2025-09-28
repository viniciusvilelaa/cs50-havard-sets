#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
unsigned char buffer[512];

int main(int argc, char *argv[])
{
    //Check command-line arguments
    if(argc != 2){
        printf("Uso: ./recover imagem\n");
        return 1;
    }

    //Open read file
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;

    }

    //Variables
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    //Find new block
    while(fread(buffer, 1, 512, input) == 512){
        //Verify if are jpeg header
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff){
            if((buffer[3] & 0xf0) == 0xe0){

                //If have openfile, close it
                if(img != NULL)
                {
                    fclose(img);
                }

                counter++;
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "wb");
            }

        }

        //If have open file, write
        if(img != NULL){
            fwrite(buffer, 1, 512, img);
        }
    }


// Close files
    fclose(img);
    fclose(input);


}
