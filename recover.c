#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check if there's only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the Memory card (using f_i as file input)
    FILE *f_i = fopen(argv[1], "r");

    // Check if the file input is invalid
    if (f_i == NULL)
    {
        printf("Invalid file.\n");
        return 1;
    }

    // If using unsigned char I can consume all of the 512 bits from the memory
    BYTE buffer[BLOCK_SIZE];

    // Creating a int to using as "image counter" (icounter) I can keep track of how much images I get from the memory card
    int i_counter = 0;

    // File* for the recovered images (using f_o as file output)
    FILE *f_o = NULL;

    // Creat a character poiter to my file using the 8-bit unsigned integer
    char pics_file[8];

    // Loop through:

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, f_i))
    {

        // Checking for the iniciating bytes of an JPEG image using a boolean for the 4th byte
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (i_counter == 0)
            {
                // print images in "pics" file with the asked nomenclature
                sprintf(pics_file, "%03i.jpg", i_counter);

                // Opens the "pics_file" file
                f_o = fopen(pics_file, "w");

                // Write if condition is filled
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, f_o);

                // Update image counter
                i_counter++;
            }
            else if (i_counter > 0)
            {
                // Close file output
                fclose(f_o);

                // print images in "pics" file with the asked nomenclature
                sprintf(pics_file, "%03i.jpg", i_counter);

                // Opens the "pics_file" file
                f_o = fopen(pics_file, "w");

                // Write if condition is filled
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, f_o);

                // Update image counter
                i_counter++;
            }
        }

        // If the file output is valid, we can write the images
        else if (i_counter > 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, f_o);
        }

    }
    // fclose to close the file of the input
    fclose(f_i);

    // fclose to close the file of the output
    fclose(f_o);
}