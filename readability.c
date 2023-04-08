#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float grade_level(int index);

int main(void)
{
    // Aquiring the users input
    string text = get_string("Text:");

    int nlet = count_letters(text);
    int nwords = count_words(text);
    int nsent = count_sentences(text);

    // Printing the number of the data below
    //printf ("%i letters\n", nlet);
    //printf ("%i words\n", nwords);
    //printf ("%i sentences\n", nsent);

    // Calculating the Coleman-Liau formula with the text given
    float L = (float) nlet / (float) nwords * 100;
    float S = (float) nsent / (float) nwords * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // Printing the result as a Grade number
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// Function to count the number of letters in the text
int count_letters(string text)
{
    // Keep track of the number of letters
    int nlet = 0;

    // Everytime a character is found, it ads 1 ro "nlet" variable
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            nlet ++;
        }
    }
    return nlet;
}

// Function to count the number of word in the text
int count_words(string text)
{
    // Keep track of the number of words
    int nwords = 1;

    // "John is my friend" has 3 whitespaces, so it has 4 words
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            nwords ++;
        }
    }
    return nwords;
}

// Function to count the number of sentences in the text
int count_sentences(string text)
{
    // Keep track of the number of sentences
    int nsent = 0;

    // Everytime a ".", "!" or "?" is found, a sentence is count
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            nsent ++;
        }
    }
    return nsent;
}
