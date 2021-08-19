#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    float dollars = -1;

    // Checks for valid values and converts to int value
    while (dollars <= 0)
    {
        dollars = get_float("Change owde: ");
    }
    int cents = round(dollars * 100);

    int remain = cents;
    while (remain >= 25)
    {
        remain -= 25;
        coins += 1;
    }
    while (remain >= 10)
    {
        remain -= 10;
        coins += 1;
    }
    while (remain >= 5)
    {
        remain -= 5;
        coins += 1;
    }
    while (remain >= 1)
    {
        remain -= 1;
        coins += 1;
    }

    printf("Minimum amount of coins: %i\n", coins);
}
