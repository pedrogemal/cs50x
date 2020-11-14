#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int check_value(string s);
int cipher_code(string p, int key);

int main(int argc, string argv[])
{
    int a = 1;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        for (int j = 0, n = strlen(argv[a]); j < n; j++)
        {

            if (isdigit(argv[a][j]) == false)
            {

            printf("Usage: ./caesar key\n");
            return 1;

            }

        }

        check_value(argv[a]);

    }
}

    int check_value(string s)
    {

    printf("%i", atoi(s));

    if (atoi(s) > 0)
    {

      for (int j = 0, n = strlen(s); j < n; j++)
        {

            if (isdigit(s[j]) == false)
            {

            printf("Usage: ./caesar key\n");
            return 1;

            }

        }
        int key = atoi(s);

        string p = get_string("plaintext: ");

        cipher_code(p, key);

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    return 1;

    }

int cipher_code(string p, int key){

        printf("ciphertext: ");

        for (int j = 0, n = strlen(p); j < n; j++){

        // Convert ASCII to alphabetical index
        if (isalpha(p[j]) && isupper(p[j])){

             int c = p[j] - 65;

             int c1 = (c + key) % 26;

             int c2 = c1 + 65;

             char c3 = c2;
             printf("%c", c3);

        }
        else if (isalpha(p[j]) && islower(p[j]))
        {
             int c = p[j] - 97;

             int c1 = (c + key) % 26;

             int c2 = c1 + 97;

             char c3 = c2;
             printf("%c", c3);

        }
        else
        {
            printf("%c", p[j]);
        }

        }

        printf("\n");
        return 0;
}