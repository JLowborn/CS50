// Index = 0.0588 * L - 0.296 * S - 15.8
// L = Letters ÷ Words × 100 = 639 ÷ 119 × 100 ≈ 537
// S = Sentences ÷ Words × 100 = 5 ÷ 119 × 100 ≈ 4.20

#include <stdio.h>      // printf function
#include <cs50.h>       // string and get_string functions
#include <math.h>       // Round function
#include <ctype.h>      // Verify character type
#include <string.h>     // Strlen function

int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    float lAverage = 0;
    float sAverage = 0;
    float index = 0;

    string phrase = get_string("Text: ");

    // Count letters, words and sentences
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        if (isalpha(phrase[i]))
        {
            letters += 1;
        }

       if (isalpha(phrase[i]) && (isspace(phrase[i - 1]) || phrase[i - 1] == '\0' || phrase[i - 1] == '"'))
        {
            words += 1;
        }

        if (phrase[i] == '!' || phrase[i] == '?' || phrase[i] == '.')
        {
            sentences += 1;
        }
    }


    // Take letters and sentences average
    lAverage = ((float) letters / (float) words) * 100;
    sAverage = ((float) sentences / (float) words) * 100;
    index = (0.0588 * lAverage) - (0.296 * sAverage) - 15.8;

    // Verify answer before printing
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}