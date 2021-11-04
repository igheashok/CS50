#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //User input
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n >= 9);

//Main code
    for (int l = n; l > 0; l--)
    {

//First half of the pyramid
        for (int k = (l - 1); k > 0; k--)
        {
            printf(" ");
        }

        for (int i = l; i <= n; i++)
        {
            printf("#");
        }

//For space at the centre
        printf("  ");

//Second half of the pyramid
        for (int i = l; i <= n; i++)
        {
            printf("#");
        }

        printf("\n");
    }
}
