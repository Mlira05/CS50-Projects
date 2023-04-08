#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Add the string and get_string type to ask for the input
    string name = get_string("What's your name?\n");

    //Use function printf to print results
    printf("Hello, %s!\n", name);
}