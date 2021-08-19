#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int h = 0; // Stair height
    string stairs = "########";
    string space = "        ";

    // Check for valid input in range
    while (h < 1 || h > 8)
    {
        h = get_int("Height: ");
    }

    // Print stairs
    int c = h - 1; // Counter
    for (int i = 1; i < h + 1; i++)
    {
        printf("%.*s", c, space);
        printf("%.*s", i, stairs);
        printf("\n");
        c--;
    }
}