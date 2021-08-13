#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Prototypes//
int letter_Counter(string sampleText);
int word_Counter(string sampleText);
int sentence_Counter(string sampleText);
int grade_Counter(int letters, int words, int sentences);


int main(void)
{
    string text = get_string("Text: ");                                                     //User input
    printf("%d letter(s)\n", letter_Counter(text));                                         //Output for letters count
    printf("%d word(s)\n", word_Counter(text));                                             //Output for words count
    printf("%d sentence(s)\n", sentence_Counter(text));                                     //Output for sentence count
    grade_Counter(letter_Counter(text), word_Counter(text), sentence_Counter(text));        //Final output for grade count
}




//Declaration of a function to count Letters//
int letter_Counter(string sampleText)
{
    int letterCount = 0;

    for (int i = 0, length = strlen(sampleText); i < length; i++)
    {
        sampleText[i] = toupper(sampleText[i]);
        if (isupper(sampleText[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}




//Declaration of a function to count Words//
int word_Counter(string sampleText)
{
    int wordCount = 0;
    for (int i = 0, length = strlen(sampleText); i < length; i++)
    {
        if (isspace(sampleText[i]))
        {
            wordCount++;
        }
    }
    return ++wordCount;                                                                         //++ to include the last remaining word 
}




//Declaration of a function to count Sentences//
int sentence_Counter(string sampleText)
{
    int sentenceCount = 0;
    char specialChar[] = {'.', '!', '?'};
    for (int i = 0, length = strlen(sampleText); i < length; i++)
    {
        if ((sampleText[i] == specialChar[0]) || (sampleText[i] == specialChar[1]) || (sampleText[i] == specialChar[2]))
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}




//Declaration of a function to count Grade//
int grade_Counter(int letters, int words, int sentences)
{
    float L = (letters / (float) words) * 100.000;
    float S = (sentences / (float) words) * 100.000;
    int grade = (int) round((0.0588 * L) - (0.296 * S) - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
    return grade;
}
