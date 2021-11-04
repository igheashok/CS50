#include "helpers.h"
#include <math.h>

// Convert image to grayscale //
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            float average = ((image[i][k].rgbtRed) + (image[i][k].rgbtGreen) + (image[i][k].rgbtBlue)) / 3.0;
            average = round(average);
            image[i][k].rgbtRed = average;
            image[i][k].rgbtGreen = average;
            image[i][k].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia //
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (red > 255)
            {
                red = 255;
            }
            else if (red < 0)
            {
                red = 0;
            }

            if (green > 255)
            {
                green = 255;
            }
            else if (green < 0)
            {
                green = 0;
            }

            if (blue > 255)
            {
                blue = 255;
            }
            else if (blue < 0)
            {
                blue = 0;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Reflect image horizontally //
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        int l = 0;
        for (int k = width - 1; k > ((width - 1) / 2.0); k--)
        {
            RGBTRIPLE buffer;
            buffer = image[i][k];
            image[i][k] = image[i][l];
            image[i][l] = buffer;
            l++;
        }
    }
    return;
}

// Blur image //
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Creation of buffer file
    RGBTRIPLE temp[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            float counter = 0.00;
            
            // **Gathering data from neighbouring pixel** //
            
            //Neighbour pixel: 1
            if (i > 0 && k > 0)
            {
                sumRed += image[i - 1][k - 1].rgbtRed;
                sumGreen += image[i - 1][k - 1].rgbtGreen;
                sumBlue += image[i - 1][k - 1].rgbtBlue;
                counter++;
            }

            //Neighbour pixel: 2
            if (i > 0)
            {
                sumRed += image[i - 1][k].rgbtRed;
                sumGreen += image[i - 1][k].rgbtGreen;
                sumBlue += image[i - 1][k].rgbtBlue;
                counter++;
            }

            //Neighbour pixel: 3
            if (i > 0 && k < (width - 1))
            {
                sumRed += image[i - 1][k + 1].rgbtRed;
                sumGreen += image[i - 1][k + 1].rgbtGreen;
                sumBlue += image[i - 1][k + 1].rgbtBlue;
                counter++;
            }

            //Neighbour pixel: 4
            if (k < (width - 1))
            {
                sumRed += image[i][k + 1].rgbtRed;
                sumGreen += image[i][k + 1].rgbtGreen;
                sumBlue += image[i][k + 1].rgbtBlue;
                counter++;
            }

            //Neighbour pixel: 5
            if (i < (height - 1) && k < (width - 1))
            {
                sumRed += image[i + 1][k + 1].rgbtRed;
                sumGreen += image[i + 1][k + 1].rgbtGreen;
                sumBlue += image[i + 1][k + 1].rgbtBlue;
                counter++;
            }

            //Neighbour pixel: 6
            if (i < (height - 1))
            {
                sumRed += image[i + 1][k].rgbtRed;
                sumGreen += image[i + 1][k].rgbtGreen;
                sumBlue += image[i + 1][k].rgbtBlue;
                counter++;
            }

            //Neighbour pixel: 7
            if (i < (height - 1) && k > 0)
            {
                sumRed += image[i + 1][k - 1].rgbtRed;
                sumGreen += image[i + 1][k - 1].rgbtGreen;
                sumBlue += image[i + 1][k - 1].rgbtBlue;
                counter++;
            }

            //Neighbour pixel: 8
            if (k > 0)
            {
                sumRed += image[i][k - 1].rgbtRed;
                sumGreen += image[i][k - 1].rgbtGreen;
                sumBlue += image[i][k - 1].rgbtBlue;
                counter++;
            }

            //Sum
            sumRed += image[i][k].rgbtRed;
            sumGreen += image[i][k].rgbtGreen;
            sumBlue += image[i][k].rgbtBlue;
            counter++;
            
            //Average
            int averageRed = round(sumRed / counter);
            int averageGreen = round(sumGreen / counter);
            int averageBlue = round(sumBlue / counter);
            
            //New values assignment
            temp[i][k].rgbtRed = averageRed;
            temp[i][k].rgbtGreen = averageGreen;
            temp[i][k].rgbtBlue = averageBlue;
        }
    }

    // Transfer buffer data to original file //
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtRed = temp[i][k].rgbtRed;
            image[i][k].rgbtGreen = temp[i][k].rgbtGreen;
            image[i][k].rgbtBlue = temp[i][k].rgbtBlue;
        }
    }
    return;
}
