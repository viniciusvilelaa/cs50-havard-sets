#include "helpers.h"
#include <math.h>
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int Gx[3][3]= {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };


    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            int gxRed = 0;
            int gxGreen = 0;
            int gxBlue = 0;
            int gyRed = 0;
            int gyGreen = 0;
            int gyBlue = 0;

            for(int dh = -1; dh <= 1; dh++){
                for(int dw = -1; dw <=1; dw++){
                    int nh = h + dh;
                    int nw = w + dw;

                    if(nh >= 0 && nh < height && nw >= 0 && nw < width){
                        int pixelRed = image[nh][nw].rgbtRed;
                        int pixelGreen = image[nh][nw].rgbtGreen;
                        int pixelBlue = image[nh][nw].rgbtBlue;

                        int gx = Gx[dh + 1][dw + 1];
                        int gy = Gy[dh+1][dw+1];

                        gxRed += pixelRed * gx;
                        gxGreen += pixelGreen * gx;
                        gxBlue += pixelBlue * gx;

                        gyRed += pixelRed * gy;
                        gyGreen += pixelGreen * gy;
                        gyBlue += pixelBlue * gy;

                    }

                }
            }

            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));

            if(red > 255){
                red = 255;
            }
            if(green > 255){
                green = 255;
            }
            if(blue > 255){
                blue = 255;
            }

            temp[h][w].rgbtRed = red;
            temp[h][w].rgbtBlue = blue;
            temp[h][w].rgbtGreen = green;


        }
    }

    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            image[h][w] = temp[h][w];
        }
    }
    return;
}
