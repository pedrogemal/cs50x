#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

typedef uint8_t byte;
bool isjpg_header(byte *block);

int main(int argc, char *argv[])
{

    char *buffer;

    if (argc != 2)
    {
        printf("Inform one single file as an argument.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Please use a valid file to be recovered. Could not open %s.\n", argv[1]);
        return 1;
    }

    FILE *JPG;

    // Temporary storage (buffer) for block.
    byte block[512];

    bool foundjpg = false;
    int readblock;
    int jpgnum = 0;

    while (fread(block, sizeof(block), 1, file) == 1)
    {

        if (isjpg_header(block))
        {

            char filename[8];

            sprintf(filename, "%03.3i.jpg", jpgnum);

            if (foundjpg == true)
            {
                fclose(JPG);
            }
            else
            {
                // First jpg
                foundjpg = true;
            }

            JPG = fopen(filename, "w");
            fwrite(block, sizeof(block), 1, JPG);

            jpgnum++;

        }

        else

        {
            if (foundjpg == true)
            {
                fwrite(block, sizeof(block), 1, JPG);

            }

        }

    }

    fclose(file);
    fclose(JPG);

}

bool isjpg_header(byte *block)
{
    if (block[0] == 0xff &&
        block[1] == 0xd8 &&
        block[2] == 0xff &&
        (block[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}