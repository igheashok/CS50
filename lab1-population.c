#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x;
    int y;
    int n = 0;

    //Prompt for start size
    do
    {
        x = get_int("Enter initial population size:\n");
    }
    while (x < 9);

    //Prompt for end size
    do
    {
        y = get_int("Enter final population size:\n");
    }
    while (y < x);

    //Calculate number of years until we reach threshold
    do
    {
        x = x + (x / 3) - (x / 4);
        n++;
    }
    while (x < y);

    //Side-effect
    printf("Years: %i\n", n);
}
