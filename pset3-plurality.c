#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(int voter_count);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner(voter_count);
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(int voter_count)
{
    int k = 0;
    string winnerNames[candidate_count];
    int counter = voter_count;

    for (int m = 0; counter > 0; counter--)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (candidates[i].votes == counter)                         //If highest vote is found
            {
                winnerNames[k] = candidates[i].name;
                k++;
                for (int j = i + 1; j < candidate_count; j++)
                {
                    if (candidates[j].votes == counter)                 //If highest vote is repeated
                    {
                        winnerNames[k] = candidates[j].name;
                        k++;
                    }
                }
                i = candidate_count;
                counter = 0;
            }
        }
    }

    //Reveal the names
    for (int i = 0; i < k; i++)
    { printf("%s\n", winnerNames[i]); }

    return;
}
