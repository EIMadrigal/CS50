#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
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
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            imageCopy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int sumBlue = 0, sumGreen = 0, sumRed = 0;
            int cnt = 0;

            for (int dx = -1; dx <= 1; ++dx)
            {
                for (int dy = -1; dy <= 1; ++dy)
                {
                    int nextx = i + dx, nexty = j + dy;
                    if (nextx >= 0 && nextx < height && nexty >= 0 && nexty < width)
                    {
                        sumBlue += imageCopy[nextx][nexty].rgbtBlue;
                        sumGreen += imageCopy[nextx][nexty].rgbtGreen;
                        sumRed += imageCopy[nextx][nexty].rgbtRed;
                        ++cnt;
                    }
                }
            }

            image[i][j].rgbtBlue = round(1.0 * sumBlue / cnt);
            image[i][j].rgbtGreen = round(1.0 * sumGreen / cnt);
            image[i][j].rgbtRed = round(1.0 * sumRed / cnt);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            imageCopy[i][j] = image[i][j];
        }
    }

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int sumBluex = 0, sumGreenx = 0, sumRedx = 0;
            int sumBluey = 0, sumGreeny = 0, sumRedy = 0;
            for (int dx = -1; dx <= 1; ++dx)
            {
                for (int dy = -1; dy <= 1; ++dy)
                {
                    int nextx = i + dx, nexty = j + dy;
                    if (nextx >= 0 && nextx < height && nexty >= 0 && nexty < width)
                    {
                        sumBluex += imageCopy[nextx][nexty].rgbtBlue * gx[dx + 1][dy + 1];
                        sumGreenx += imageCopy[nextx][nexty].rgbtGreen * gx[dx + 1][dy + 1];
                        sumRedx += imageCopy[nextx][nexty].rgbtRed * gx[dx + 1][dy + 1];
                        sumBluey += imageCopy[nextx][nexty].rgbtBlue * gy[dx + 1][dy + 1];
                        sumGreeny += imageCopy[nextx][nexty].rgbtGreen * gy[dx + 1][dy + 1];
                        sumRedy += imageCopy[nextx][nexty].rgbtRed * gy[dx + 1][dy + 1];
                    }
                }
            }
            int b = round(sqrt(1.0 * (sumBluex * sumBluex + sumBluey * sumBluey)));
            int g = round(sqrt(1.0 * (sumGreenx * sumGreenx + sumGreeny * sumGreeny)));
            int r = round(sqrt(1.0 * (sumRedx * sumRedx + sumRedy * sumRedy)));
            image[i][j].rgbtBlue = b > 255 ? 255 : b;
            image[i][j].rgbtGreen = g > 255 ? 255 : g;
            image[i][j].rgbtRed = r > 255 ? 255 : r;
        }
    }

    return;
}
