#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // thinking that height and width are the two integers that caracterize the 'pixel' itself..
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // In the background hint they use RGBTRIPLE pixel = Image, but in this case we use RGBTRIPLE image
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                // The color purple in hexadecimal is given by RGB CC8899
                (image[i][j].rgbtBlue = 0x99) && (image[i][j].rgbtGreen = 0x88) && (image[i][j].rgbtRed = 0xcc);
            }
        }
    }
}
