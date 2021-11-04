#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


void encrypt(string text, string key);                                                       //Prototype//
int isRepeated(char key[]);


int main(int argc, string argv[])
{
    if (argc != 2)                                                                          //--"COMMAND LINE ARGUMENT VALIDATION"--//
    {
        printf("Usage: ./substitution key\n");                                              //If the argument count is valid//
        return 1;
    }
    else if (strlen(argv[1]) != 26)                                                         //If key is of length 26//
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0, length = strlen(argv[1]); i < length; i++)                              //If key is an alphabet//
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    if (isRepeated(argv[1]))                                                                //Is the alphabet in the key repeated//
    {
        printf("Letters should not repeat in key\n");
        return 1;
    }


    string plainText = get_string("plaintext: ");                                           //User input//

    encrypt(plainText, argv[1]);
}


void encrypt(string text, string key)                                                       //Declaration of encryption function//
{
    char indexedText[strlen(text)];
    strcpy(indexedText, text);

    for (int i = 0, length = strlen(text); i < length; i++)                                 //Conversion to alphabetical index
    {
        if (isupper(text[i]))
        {
            indexedText[i] = indexedText[i] - 65;
        }
        else if (islower(text[i]))
        {
            indexedText[i] = indexedText[i] - 97;
        }
        else
        {
            indexedText[i] = text[i];
        }
    }


    string cipherText = text;
    printf("ciphertext: ");
    for (int i = 0, length = strlen(text); i < length; i++)                                 //Encryption//
    {
        if (isupper(text[i]))
        {
            int a = (int)indexedText[i];
            cipherText[i] = key[a];
            printf("%c", toupper(cipherText[i]));
        }
        else if (islower(text[i]))
        {
            int a = (int)indexedText[i];
            cipherText[i] = key[a];
            printf("%c", tolower(cipherText[i]));
        }
        else if (isalpha(text[i]) == 0)
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}


int isRepeated(char key[])                                                                  //IsRepeated function declaration//
{
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0, length = strlen(key); i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
