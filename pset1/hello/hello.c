#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get the string
    string name = get_string("Please, say your name:\n");

    // print the string, regardeless it is empty
    printf("hello, %s\n", name);
}