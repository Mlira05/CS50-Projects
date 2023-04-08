#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // I'll two for loops to go on throught every pixel in every row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get the images rgb values as floats
            float rgbtBlue = image[i][j].rgbtBlue;
            float rgbtGreen = image[i][j].rgbtGreen;
            float rgbtRed = image[i][j].rgbtRed;

            // In a "Average Color" int, assign the value of the colors / 3;
            int avColor = round((rgbtBlue + rgbtGreen + rgbtRed) / 3);
            image[i][j].rgbtBlue = avColor;
            image[i][j].rgbtGreen = avColor;
            image[i][j].rgbtRed = avColor;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get the images rgb values as floats
            float fBlue = image[i][j].rgbtBlue;
            float fGreen = image[i][j].rgbtGreen;
            float fRed = image[i][j].rgbtRed;

            // Int "sColor" will have the formula's result assignment already rounded
            int sBlue = round(fBlue * 0.131 + fGreen * 0.534 + fRed * 0.272);
            int sGreen = round(fBlue * 0.168 + fGreen * 0.686 + fRed * 0.349);
            int sRed = round(fBlue * 0.189 + fGreen * 0.769 + fRed * 0.393);

            // In case Blue passes 255
            if (sBlue > 255)
            {
                sBlue = 255;
            }

            // In case Green passes 255
            if (sGreen > 255)
            {
                sGreen = 255;
            }

            // In case Red passes 255
            if (sRed > 255)
            {
                sRed = 255;
            }

            // Updating the final pixel values
            image[i][j].rgbtBlue = sBlue;
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtRed = sRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // instead of going all the way through the row of pixels
        // it must go only half way, 'cause we don't wanna swap places twice
        for (int j = 0; j < width / 2; j++)
        {
            // I'll create a new variable called "temp_store" in RGBTRIPLE
            // And I'll use this variable to store the image's pixel values temporarily
            RGBTRIPLE temp_store = image[i][j];

            // Now that the image's original value is stored
            // I can change it to the value of the last pixel unchanged
            // I'll use j (width), wich marks the pixels "position"
            image[i][j] = image[i][width - (j + 1)];

            // Now I can store the value of the last pixel unchanged
            // To the inicial value of the first pixel of the row
            image[i][width - (j + 1)] = temp_store;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // First we create a copy of the original image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Then we store the original image's values into "copy"
            copy[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int allBlue = 0;
            int allGreen = 0;
            int allRed = 0;
            float nAround = 0.00;

            // For finding the values around the target pixel, I'll deal
            // With height and width as axis x and y respectively
            // And then target the actual locations of x and y using i and j
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int targetX = i + x;
                    int targetY = j + y;

                    // This condition might take out of the equation the values outside the image
                    if (targetX < 0 || targetX > (height - 1) || targetY < 0 || targetY > (width - 1))
                    {
                        // please keep going (crossing-fingers-code)
                        continue;
                    }

                    // Now I'll store in "allColor" the sum of the aroundings and
                    // Add 1 to the n of ""surroundings"" (nAround) for every valid friendly pixel around
                    allBlue += image[targetX][targetY].rgbtBlue;
                    allGreen += image[targetX][targetY].rgbtGreen;
                    allRed += image[targetX][targetY].rgbtRed;
                    nAround++;
                }

                // Then I atribute the sum of each color divided by the nAround to it's copy version
                copy[i][j].rgbtBlue = round(allBlue / nAround);
                copy[i][j].rgbtGreen = round(allGreen / nAround);
                copy[i][j].rgbtRed = round(allRed / nAround);
            }
        }
    }

    // Then, the final loop goes to going over the rows and pixels again
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Then (finally) store the new image's (copy) values into the image
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
        }
    }
    return;
}
