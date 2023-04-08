#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Command-line arguments with conditions
//argc has to be = 2 to fill the format "./caesar 2"
//argv[1] has to be only digits
int main(int argc, string argv[])
{
    // Make the conditions to the input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make the other conditions for the input
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

// Traslate the "a to i", the string to integer
    int key = atoi(argv[1]);

// Get the input for the plaintext
    string plaintext = get_string("Plaintext: ");

// Print the Ciphertext
    printf("Ciphertext: ");

    for (int j = 0; j < strlen(plaintext); j++)
    {

        // For CAPITAL letters on plaintext
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + key) % 26 + 65);
        }
        // For lower letters on plaintext
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + key) % 26 + 97);
        }
        // For other types of characters
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}







