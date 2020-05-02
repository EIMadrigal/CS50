#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            double gray = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            gray = round(gray);
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int oriB = image[i][j].rgbtBlue, oriG = image[i][j].rgbtGreen, oriR = image[i][j].rgbtRed;
            int b = round(.272 * oriR + .534 * oriG + .131 * oriB);
            int g = round(.349 * oriR + .686 * oriG + .168 * oriB);
            int r = round(.393 * oriR + .769 * oriG + .189 * oriB);
            image[i][j].rgbtBlue = b > 255 ? 255 : b;
            image[i][j].rgbtGreen = g > 255 ? 255 : g;
            image[i][j].rgbtRed = r > 255 ? 255 : r;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width / 2; ++j)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCpy[height][width];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            imageCpy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int sum[3] = {0, 0, 0};
            int cnt = 0;
            for (int m = -1; m <= 1; ++m)
            {
                for (int n = -1; n <= 1; ++n)
                {
                    if (i + m < 0 || j + n < 0 || i + m >= height || j + n >= width)
                    {
                        continue;
                    }
                    sum[0] += imageCpy[i + m][j + n].rgbtBlue;
                    sum[1] += imageCpy[i + m][j + n].rgbtGreen;
                    sum[2] += imageCpy[i + m][j + n].rgbtRed;
                    ++cnt;
                }
            }
            int b = round(1.0 * sum[0] / cnt);
            int g = round(1.0 * sum[1] / cnt);
            int r = round(1.0 * sum[2] / cnt);
            image[i][j].rgbtBlue = b > 255 ? 255 : b;
            image[i][j].rgbtGreen = g > 255 ? 255 : g;
            image[i][j].rgbtRed = r > 255 ? 255 : r;
        }
    }
}
