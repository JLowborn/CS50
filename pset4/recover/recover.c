#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CHUNK_SIZE 512

int main(int argc, char *argv[])
{
    // Check argument number
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *card_name = argv[1];  // Memory card name
    int img_counter = 0;    // Found image counter
    unsigned char buffer[CHUNK_SIZE];
    FILE *i_file = fopen(card_name, "r");   // Input file
    FILE *o_file = NULL;    // Output file
    bool found = false;     // Check for already found imgs

    // Verify file
    if (!i_file)
    {
        printf("[DEBUG] File not found: %s\n", card_name);
        return 1;
    }

    // Read whole card
    while (fread(&buffer, CHUNK_SIZE, 1, i_file) == true)
    {

        // Check for image header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (found == true)
            {
                fclose(o_file);
            }
            else
            {
                found = true;
            }

            char img_name[8]; // 000.img\0
            sprintf(img_name, "%03i.jpg", img_counter);
            o_file = fopen(img_name, "w");
            img_counter += 1;
        }

        if (found == true)
        {
            fwrite(&buffer, CHUNK_SIZE, 1, o_file);
        }
    }

    // Close unused files
    if (o_file == NULL)
    {
        fclose(o_file);
    }

    if (i_file == NULL)
    {
        fclose(i_file);
    }

    return 0;
}