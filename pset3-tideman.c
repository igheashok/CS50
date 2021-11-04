#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}





// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}





// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int k = 1;
    for (int i = 0; i <= (candidate_count - 2); i++)
    {
        for (int j = k; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
        k++;
    }
    return;
}





// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int l = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[l].winner = i;
                pairs[l].loser = j;
                pair_count++;
                l++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[l].winner = j;
                pairs[l].loser = i;
                pair_count++;
                l++;
            }
        }
    }
    return;
}





// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair sample[pair_count];

    int k = 0;
    for (int j = MAX; j > 0; j--)
    {
        for (int i = 0; i < pair_count; i++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] == j)
            {
                sample[k].winner = pairs[k].winner;
                sample[k].loser = pairs[k].loser;
                k++;
            }
        }
    }

    for (int  i = 0; i < 5; i++)
    {
        sample[i].winner = pairs[i].winner;
        sample[i].loser = pairs[i].loser;
    }

    return;
}





// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int k = 0;
    for (int i = 0; i < pair_count; i++)
    {
            locked[pairs[i].winner][pairs[i].loser] = true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (pairs[j].loser == i)
            {
                k++;
            }
        }
    }

    if (k == candidate_count)
    {
        locked[pairs[pair_count - 1].winner][pairs[pair_count - 1].loser] = false;
    }

    return;
}





// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winner;
    for (int i = 0; i < candidate_count; i++)
    {
        int loser = 0;
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[pairs[j].winner][pairs[j].loser] == true)
            {
                if (pairs[j].loser == i)
                {
                    loser++;
                }
            }
        }
        if (loser == 0)
        {
            winner = i;
        }
    }

    printf("%s", candidates[winner]);
    return;
}
