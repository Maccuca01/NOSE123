#include "helpers.h"
#include<math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  uint8_t average;
  for(int i = 0; i < height; i++)
  {
		  for(int j = 0; j < width; j++)
		  {
				average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed +image[i][j].rgbtGreen) / 3.0);
				image[i][j].rgbtBlue = average;
				image[i][j].rgbtRed = average;
				image[i][j].rgbtGreen = average;
		  }
  }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
  float originalr;
  float originalb;
  float originalg;

		for(int i = 0; i < height; i++)
		{
				for(int j = 0; j < width; j++)
				{
						 originalr = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
						 originalb = round(.272 * image[i][j].rgbtRed+ .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
						 originalg = round(.394 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

						if (originalr >= 255)
						{
						 originalr =  255;		
						}
						if (originalg >= 255)
						{
								originalg = 255;
						}
                        if (originalb >= 255)
						{
								originalb = 255;
						}
						image[i][j].rgbtRed = originalr;
						image[i][j].rgbtGreen = originalg;
						image[i][j].rgbtBlue =originalb;
				}
		}
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
		int tmp = width / 2;
		for(int i = 0; i < height; i++)
		{
				for(int j = 0; j < tmp; j++)
				{
						int red = image[i][j].rgbtRed; 
                        int blue = image[i][j].rgbtBlue; 
                        int green = image[i][j].rgbtGreen;
						image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
						image[i][j].rgbtBlue = image[i][width - j -1].rgbtBlue;
						image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
						image[i][width - j - 1].rgbtRed = red;
						image[i][width - j - 1].rgbtBlue = blue;
						image[i][width - j - 1].rgbtGreen = green;

				}
		}	
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
