#include <stdio.h>      // Print text
#include <stdlib.h>     // Converts arg into integer
#include <ctype.h>      // Check for letters to rotate
#include <cs50.h>       // For string type and get_string function
#include <string.h>     // Check plaintext length

int main(int argc, string argv[])
{

    // Checks for key
    if (argc == 2)
    {
        // Check is key is valid
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converts arg into integer and ask for user input
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    // Encipher the text and print it out
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            char lCase = 'A';
            if (islower(plaintext[i]))
            {
                lCase = 'a';
            }
            printf("%c", (plaintext[i] - lCase + key) % 26 + lCase);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}