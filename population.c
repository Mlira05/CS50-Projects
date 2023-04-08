#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size (ss)

int ss;
 do
 {
      ss = get_int("Start size: ");
 }
  while (ss < 9);

    // TODO: Prompt for end size (es)

 int es;
 do
 {
      es = get_int("End size: ");
 }
  while (es < ss);

    // TODO: Calculate number of years until we reach threshold

 int years = 0;

  while (ss < es)
  {
    ss = ss + (ss / 3) - (ss / 4);
    years++;
  }

    // TODO: Print number of years

  printf("Years: %i\n", years);

}
