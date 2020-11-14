#include <stdio.h>
#include <cs50.h>
#include <math.h>

void check(int cents);

int main(void)
{
    // Initialize the variables
    float dollars;
    int cents;

    // Run the loop to get a value of height between 1 and 8, inclusive, from the user
    do
    {
        dollars = get_float("Change owed: ");
        cents = round(dollars * 100);
    }
    while (dollars <= 0);

    // Call the function and pass value to it as a parameter
    check(cents);
}

void check(int cents){

    int quarters = cents / 25;
    int dimes = (cents % 25) / 10;
    int nickels = ((cents % 25) % 10) / 5;
    int pennies = ((cents % 25) % 10) % 5;

    printf("%d\n", quarters + dimes + nickels + pennies);

}