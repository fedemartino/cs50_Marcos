#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float ChangeOwed;
    int Coins, Quarters, Dimes, Nickles, Pennies;

    do
    {
        ChangeOwed = get_float("Change owed: ");
    }
    while (ChangeOwed < 0);

    int cents = round(ChangeOwed * 100);

    for (Quarters = 0; cents >= 25; Quarters++)
    {
        cents = (cents - 25);
    }
    for (Dimes = 0; cents >= 10; Dimes++)
    {
        cents = (cents - 10);
    }
    for (Nickles = 0; cents >= 5; Nickles++)
    {
        cents = (cents - 5);
    }
    for (Pennies = 0; cents >= 1; Pennies++)
    {
        cents = (cents - 1);
    }

    Coins = (Quarters + Dimes + Nickles + Pennies);

    printf("%i\n", Coins);

}