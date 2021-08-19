#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void encrypt(string text, int k);                                                       //Prototype//


int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Please enter a single arguement\n");
        return 1;
    }
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);                                                              //Conversion of argv to int//

    string plainText = get_string("plaintext: ");                                       //User input for text//

    encrypt(plainText, k);                                                              //Calling the encrypt function//
}




void encrypt(string text, int k)                                                        //Encrypt function declaration//
{
    char indexedText[100];
    char cipherText[100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0, length = strlen(text); i < length; i++)                             //Conversion to alphabetical index
    {
        if (isupper(text[i]))
        {
            indexedText[i] = text[i] - 65;
        }
        else if (islower(text[i]))
        {
            indexedText[i] = text[i] - 97;
        }
        else
        {
            indexedText[i] = text[i];
        }

        cipherText[i] = (indexedText[i] + k) % 26;                                      //Encryption into cipher text
    }


    for (int i = 0, length = strlen(text); i < length; i++)                             //Reconversion to ASCII index
    {
        if (isupper(text[i]))
        {
            cipherText[i] = cipherText[i] + 65;
        }
        else if (islower(text[i]))
        {
            cipherText[i] = cipherText[i] + 97;
        }
        else
        {
            cipherText[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", cipherText);
}
