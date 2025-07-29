#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main (void)
{
    // prompt first player
    string playerOne = get_string("Player 1: ");

    // prompt second player
    string playerTwo = get_string("Player 2: ");

    // transform the given word to points
    int playerOneScore = compute_score(playerOne);
    int playerTwoScore = compute_score(playerTwo);

    // output the winner
    if (playerOneScore > playerTwoScore)
    {
        printf("Player 1 wins!\n");
    }
    else if (playerTwoScore > playerOneScore)
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
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
        else
        {
            score += 0;
        }
    }

    return score;
}