#include <stdio.h>
#include <cs50.h>

// I don't really think this code need comments ...

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("Hello, %s.\n", name);
}