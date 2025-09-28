#include "helpers.h"


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    long media = 0;
    for(int h = 0; h <= height; h++){
        for(int w = 0; w <= width; w++){
            media = (image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3 ;
            image[h][w].rgbtRed = media;
            image[h][w].rgbtGreen = media;
            image[h][w].rgbtBlue = media;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            int originalRed = image[h][w].rgbtRed;
            int originalGreen = image[h][w].rgbtGreen;
            int originalBlue = image[h][w].rgbtBlue;

            int sepiaRed = (int) round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = (int) round(.349 * originalRed + .686  * originalGreen + .168 * originalBlue);
            int sepiaBlue =  (int) round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if(sepiaRed > 255){
                sepiaRed = 255;
            }
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for(int h = 0; h < height; h++){
        for(int w = 0; w < width / 2; w++){
            RGBTRIPLE temp = image[h][w];

            image[h][w] = image[h][width - 1 - w];
            image[h][width - 1 - w] = temp;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            int sumRed = 0;
            int sumBlue = 0;
            int sumGreen = 0;
            int count = 0;

            for(int dh = -1; dh <= 1; dh++){
                for(int dw = -1; dw <=1; dw++){
                    int nh = h + dh;
                    int nw = w + dw;

                    if(nh >= 0 && nh < height && nw >= 0 && nw < width){
                        sumRed += image[nh][nw].rgbtRed;
                        sumBlue += image[nh][nw].rgbtBlue;
                        sumGreen += image[nh][nw].rgbtGreen;
                        count++;
                    }

                }
            }

            temp[h][w].rgbtRed = sumRed / count;
            temp[h][w].rgbtBlue = sumBlue / count;
            temp[h][w].rgbtGreen = sumGreen / count;


        }
    }

    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            image[h][w] = temp[h][w];
        }
    }
    return;
}
