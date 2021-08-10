#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

float average(int total, int scores[]);												     		//Prototype
int passwordChecker(string password);


int main(int argc, string argv[])
{
	string a = get_string("Enter the password: ");                                              //User Input
    if (passwordChecker(a))
	{

		printf("Initiating process...\n\nHello, %c", toupper(argv[1][0]));						//Greetings
		for (int i = 1, j = strlen(argv[1]); i < j; i++)
		{
			printf("%c", tolower(argv[1][i]));
		}
		printf("\n\n");




	//  	  STARTING OF SCORE CODE    	 //

		int total = get_int("Enter the total number of scores: ");								//User Input For Number Of Scores

		int scores[total];
		for (int j = 0; j < total; j++)
		{
			scores[j] = get_int("Enter the score: ");
		}
		printf("The average is: %.2f\n", average(total, scores));
	}
	else
	{
		printf("Incorrect Password! Try again.\n");
	}
}




	//			AVERAGE FUNCTION DECLARATION			//

float average(int total, int scores[])
{
	int sum = 0;
	for (int i = 0; i < total; i++)
	{
		sum = sum + scores[i];
	}
	return sum / (float) total;
}




	//			PASSWORD FUNCTION DECLARATION				//

int passwordChecker(string password)
{
    int passwordLength = strlen(password);
    if (passwordLength == 5)
    {
        if (strcmp(password, "ashok") == 0)
        {
            printf("\nPassword Correct!\n\n");
            return 1;
        }
        else {  printf("\nPassword Incorrect!\n\n");
        	return 0;	}
    }
    else {  printf("\nPassword Incorrect!\n\n");
    		return 0;	}
}
