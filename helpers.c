#include "helpers.h"

void swap(unsigned char *a, unsigned char *b);
float roundn(float a);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float AVERAGE = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            average = roundn(AVERAGE);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed;
    int originalGreen;
    int originalBlue;

    int sepia[3];

    float SEPIA[3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            SEPIA[0] = 0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue;
            SEPIA[1] = 0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue;
            SEPIA[2] = 0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue;

            for (int k = 0; k < 3; k++)
            {
                int intSEPIA = SEPIA[k];
                if (SEPIA[k] >= 255)
                SEPIA[k] = 255;
                else if (SEPIA[k] <= 0)
                SEPIA[k] = 0;

                if (SEPIA[k] - 0.5 < intSEPIA)
                sepia[k] = SEPIA[k];
                else
                sepia[k] = SEPIA[k] + 1;
            }

        image[i][j].rgbtRed = sepia[0];
        image[i][j].rgbtGreen = sepia[1];
        image[i][j].rgbtBlue = sepia[2];

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= (width / 2) - 1; j++)
        {
            swap(&image[i][j].rgbtRed, &image[i][(width - 1) - j].rgbtRed);
            swap(&image[i][j].rgbtGreen, &image[i][(width - 1) - j].rgbtGreen);
            swap(&image[i][j].rgbtBlue, &image[i][(width - 1) - j].rgbtBlue);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float sumRed, sumGreen, sumBlue;
    int originalRed[height][width];
    int originalGreen[height][width];
    int originalBlue[height][width];

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            originalRed[a][b] = image[a][b].rgbtRed;
            originalGreen[a][b] = image[a][b].rgbtGreen;
            originalBlue[a][b] = image[a][b].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float count = 0;
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;


            for (int k = (i - 1); k <= (i + 1); k++)
            {
                if (k >= 0 && k < height)
                {
                    for (int l = (j - 1); l <= (j + 1); l++)
                    {
                        if (l >= 0 && l < width)
                        {
                            count++;
                            sumRed += originalRed[k][l];
                            sumGreen += originalGreen[k][l];
                            sumBlue += originalBlue[k][l];
                        }
                    }
                }

            }
            image[i][j].rgbtRed = roundn(sumRed/count);
            image[i][j].rgbtGreen = roundn(sumGreen/count);
            image[i][j].rgbtBlue = roundn(sumBlue/count);
        }
    }


    return;
}



void swap(unsigned char *a, unsigned char *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

float roundn(float a)
{
    int d;
    int b = a;
    float c = a - b;

    if (c < 0.5)
        d = a;
    else
        d = (a - c) + 1;

    return d;
}
