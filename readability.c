#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau(int letters, int words, int sentences);

int main(void)
{
    // Prompt a sentence
    string text = get_string("Text: ");

    // Count the number of words, letters and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index (index = 0.0588 * L - 0.296 * S - 15.8)
    int readability = coleman_liau(letters, words, sentences);

    // Output the read level
    if (readability < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readability >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", readability);
    }
}

int count_letters(string text)
{
    int score = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            score++;
        }
    }

    return score;
}

int count_words(string text)
{
    int score = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            score++;
        }
    }

    return score;
}

int count_sentences(string text)
{
    int score = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            score++;
        }
    }

    return score;
}

int coleman_liau (int letters, int words, int sentences)
{
    float index = 0.0588 * (((float) letters / (float) words)) * 100 - 0.296 * (((float) sentences / (float) words) * 100) - 15.8;
    return (int) round(index);
}