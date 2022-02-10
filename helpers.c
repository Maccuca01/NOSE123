#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
        for (int i = 0; i < height; i++) {
           for (int j = 0; j < width; j++) {
               copy[i][j] = image[i][j];
           } 
        }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int rtotal = 0;
            int gtotal = 0;
            int btotal = 0;
            int ptotal = 0;
            if (i-1 > 0 && i-1 < height) {
                if (j-1 > 0 && j-1 < width) {
                    ptotal++;
                    rtotal += copy[i-1][j-1].rgbtRed;
                    gtotal += copy[i-1][j-1].rgbtGreen;
                    btotal += copy[i-1][j-1].rgbtBlue;
                }
                if (j > 0 && j < width) {
                    ptotal++;
                    rtotal += copy[i-1][j].rgbtRed;
                    gtotal += copy[i-1][j].rgbtGreen;
                    btotal += copy[i-1][j].rgbtBlue;
                }
                if (j+1 > 0 && j+1 < width) {
                    ptotal++;
                    rtotal += copy[i-1][j+1].rgbtRed;
                    gtotal += copy[i-1][j+1].rgbtGreen;
                    btotal += copy[i-1][j+1].rgbtBlue;
                }
           }
            if (i > 0 && i < height) {
                if (j-1 > 0 && j-1 < width) {
                    ptotal++;
                    rtotal += copy[i][j-1].rgbtRed;
                    gtotal += copy[i][j-1].rgbtGreen;
                    btotal += copy[i][j-1].rgbtBlue;
                }
                if (j > 0 && j < width) {
                    ptotal++;
                    rtotal += copy[i][j].rgbtRed;
                    gtotal += copy[i][j].rgbtGreen;
                    btotal += copy[i][j].rgbtBlue;
                }
                if (j+1 > 0 && j+1 < width) {
                    ptotal++;
                    rtotal += copy[i][j+1].rgbtRed;
                    gtotal += copy[i][j+1].rgbtGreen;
                    btotal += copy[i][j+1].rgbtBlue;
                }
           }
            if (i+1 > 0 && i+1 < height) {
                if (j-1 > 0 && j-1 < width) {
                    ptotal++;
                    rtotal += copy[i+1][j-1].rgbtRed;
                    gtotal += copy[i+1][j-1].rgbtGreen;
                    btotal += copy[i+1][j-1].rgbtBlue;
                }
                if (j > 0 && j < width) {
                    ptotal++;
                    rtotal += copy[i+1][j].rgbtRed;
                    gtotal += copy[i+1][j].rgbtGreen;
                    btotal += copy[i+1][j].rgbtBlue;
                }
                if (j+1 > 0 && j+1 < width) {
                    ptotal++;
                    rtotal += copy[i+1][j+1].rgbtRed;
                    gtotal += copy[i+1][j+1].rgbtGreen;
                    btotal += copy[i+1][j+1].rgbtBlue;
                }
            image[i][j].rgbtRed = round(rtotal/ptotal);
            image[i][j].rgbtGreen = round(gtotal/ptotal);
            image[i][j].rgbtBlue = round(btotal/ptotal); 
           }
            
        }
    }
    return;
}
