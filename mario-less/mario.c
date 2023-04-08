#include <cs50.h>
#include <stdio.h>

int main(void)
{
//Asking the user for the input (height)
int h;
do
{
h = get_int("Height: ");
}
while (h < 1 || h > 8);

//Loops for spaces and hashes
//First Loop, for jumping the lines
for (int i = 1; i <= h; i++)
{
//Loop for the spaces in cascate
for (int j = (h - i); j > 0; j--)
 {
printf(" ");
 }
//Loop for the hashes
  for (int k = (h - i); k < h; k++)
  {
  printf("#");
  }

printf("\n");
}
}

