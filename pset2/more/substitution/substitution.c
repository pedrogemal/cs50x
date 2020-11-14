#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void prompt_user(string s);
void cipher_code(string p, string key);
void alpha_arr_value(char pos, string key);

int main(int argc, string argv[])
{
    int a = 1;

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {

        for (int j = 0, n = strlen(argv[a]); j < n; j++)
        {

            for (int k = j + 1; k < strlen(argv[a]); k++)
            {
                if (argv[a][j] == argv[a][k])
                {
                printf("Key must not contain repeated characters.\n");
                return 1;
                }
            }

            if (isalpha(argv[a][j]) == false)
            {

            printf("Key must only contain alphabetic characters.\n");
            return 1;

            }
            else if (strlen(argv[a]) != 26)
            {

            printf("Key must contain 26 characters.\n");
            return 1;

            }

        }

         prompt_user(argv[a]);
         return 0;
    }

}

void prompt_user(string key)
    {

        string p = get_string("plaintext: ");

        cipher_code(p, key);

    }

void cipher_code(string p, string key){

        printf("ciphertext: ");

        for (int i = 0; i < strlen(p); i++)
        {
            if (isalpha(p[i]))
            {
                char x = p[i];
                if (islower(p[i]))
                {
                    alpha_arr_value(tolower(x), key);
                }
                else
                {
                    alpha_arr_value(toupper(x), key);
                }


            }
            else
            {
                printf("%c", p[i]);
            }
        }

        printf("\n");

}

void alpha_arr_value(char p, string key) // passing p[i] and upper/lower(alpha array)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < strlen(alpha); i++)
    {
        if (islower(p)) // p[i] is lower
        {
            if (p == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else // for UPPERCASE // p[i] is upper
        {
            if (p == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}