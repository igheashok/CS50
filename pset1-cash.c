#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
//User Prompt
    float i;
    do
    {
        i = get_float("Change owed: ");
    }
    while (i < 0);


//Conversion and round-up
    int cents = round(i * 100);


//Coin count
    int j = 0;
    while (cents >= 25)
    {
        cents -= 25;
        j++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        j++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        j++;
    }

    while (cents >= 1)
    {
        cents -= 1;
        j++;
    }

//Final Output
    printf("%i\n", j);
}
