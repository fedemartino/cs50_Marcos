#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

string abc = "abcdefghijklmnopqrstuvwxyz";

int compute_score(string word);

int main(void)
{
    // Get input words from both players

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string

    int word_len = strlen(word);
    int letters = strlen(abc);

    int score = 0;
    string WORD = word;

    for (int i = 0; i <= (word_len - 1); i++)
    {
        WORD[i] = tolower(word[i]);
        
        for (int j = 0; j <= (letters - 1); j++)
        {
            if (WORD[i] == abc[j])
            {
                score += POINTS[j];
            }
        }
    }
    return score;
}
