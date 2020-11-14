#include <stdio.h>
#include <cs50.h>

void buildPyramid(int height);

int main(void)
{
    // Initialize the variable height
    int height;

    // Run the loop to get a value of height between 1 and 8, inclusive, from the user
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Call the function and pass height to it as a parameter
    buildPyramid(height);
}

// Declare the function buildPyramid
void buildPyramid(int height)
{
    //        #  #         7 + 1 + 2 + 1
    //       ##  ##        6 + 2 + 2 + 2
    //      ###  ###       5 + 3 + 2 + 5
    //     ####  ####      4 + 4 + 2 + 4
    //    #####  #####     3 + 5 + 2 + 3
    //   ######  ######    2 + 6 + 2 + 6
    //  #######  #######   1 + 7 + 2 + 7
    // ########  ########  0 + 8 + 2 + 8

    // Loop to add a new line
    for (int i = 0; i < height; i++)
    {
        // Loop to add spaces
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }
        // Loop to add hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // Loop to add hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
