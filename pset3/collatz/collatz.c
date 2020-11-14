#include <stdio.h>
#include <cs50.h>

int collatz(int i);

int main(void){

    int i = 0;

    do

    {
    i = get_int("Say a positive number: ");
    }
    while (i < 1);

    int c = collatz(i);
    printf("%i\n", c);

}

int collatz(int i){

    if (i == 1)
        return 0;

    else if ((i % 2) == 0)
        return 1 + collatz(i/2);

    else
        return 1 + collatz (3*i + 1);

}