#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

bool isValidCard(long cardNumber);                                            //Prototypes
bool isValidAmexCard(long cardNumber);
bool isValidVisaCard(long cardNumber);
bool isValidMasterCard(long cardNumber);

int main()
{
    long n = get_long("Number: ");                                            //USER INPUT

    if (isValidCard(n))                                                       //DETERMINING WHETHER THE CARD IS A VALID CARD
    {
        if (isValidAmexCard(n))                                               //DETERMINING WHETHER THE CARD IS AN AMERICAN EXPRESS CARD
        {
            printf("AMEX\n");
        }
        else if (isValidVisaCard(n))                                          //DETERMINING WHETHER THE CARD IS A VISA CARD
        {
            printf("VISA\n");
        }
        else if (isValidMasterCard(n))                                        //DETERMINING WHETHER THE CARD IS A MASTER CARD
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}



bool isValidCard(long cardNumber)                                               //IF THE CARD IS A VALID CARD
{
    int sum = 0;
    long presentNumber = cardNumber;

    for (int i = 0; presentNumber > 1; i++)
    {
        int digit = presentNumber % 10;
        if (i % 2 == 0)                                                          //Addition of even numbers
        {
            sum = sum + digit;
        }
        else
        {
            if (digit > 4)
            {
                sum = sum + ((digit * 2) % 10) + ((digit * 2) / 10);              //Multiplication by 2, and addition of odd numbers
            }
            else
            {
                sum = sum + (digit * 2);
            }
        }
        presentNumber  = presentNumber / 10;
    }

    return (sum % 10 == 0);
}





bool isValidAmexCard(long cardNumber)                                                //IF THE CARD IS AN AMERICAN EXPRESS CARD
{
    int digitCount = 0;
    long presentNumber = cardNumber;

    for (int i = 0; presentNumber > 1; i++)
    {
        presentNumber  = presentNumber / 10;
        digitCount++;
    }

    long firstTwoDigits;
    if (digitCount == 15)
    {
        firstTwoDigits = cardNumber / (1e13);
    }
    return ((digitCount == 15) && (firstTwoDigits == 34 || firstTwoDigits == 37));
}






bool isValidVisaCard(long cardNumber)                                                   //IF THE CARD IS A VISA CARD
{
    int digitCount = 0;
    long presentNumber = cardNumber;

    for (int i = 0; presentNumber > 1; i++)
    {
        presentNumber  = presentNumber / 10;
        digitCount++;
    }

    long firstDigit;
    if (digitCount == 13)
    {
        firstDigit = cardNumber / (1e12);
    }
    else if (digitCount == 16)
    {
        firstDigit = cardNumber / (1e15);
    }
    return (((digitCount == 13) || (digitCount == 16)) && (firstDigit == 4));
}





bool isValidMasterCard(long cardNumber)                                                      //IF THE CARD IS A MASTER CARD
{
    int digitCount = 0;
    long presentNumber = cardNumber;

    for (int i = 0; presentNumber > 1; i++)
    {
        presentNumber  = presentNumber / 10;
        digitCount++;
    }

    long firstTwoDigits;
    if (digitCount == 16)
    {
        firstTwoDigits = cardNumber / (1e14);
    }
    return ((digitCount == 16) && (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55));
}
