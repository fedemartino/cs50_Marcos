#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    float m;
    int totalCoins, quarters, dimes, nickels, pennies;
    
    do
    {
        m = get_float ("Change owed: ");
    }
    while (m < 0);
    //esta variable representa el cambio total en centavos como numero entero
    int cents = round(m * 100);
    
    for (quarters = 0; cents >= 25; quarters++)
    {
        cents = (cents - 25);
    }
    for (dimes = 0; cents >= 10; dimes++)
    {
        cents = (cents - 10); 
    }
        
    for (nickels = 0; cents >= 5; nickels++)
    {
        cents = (cents - 5);
    }
    pennies = (cents - 1);

    totalCoins = quarters + dimes + nickels + pennies;   
    
    printf("%i\n", totalCoins);
   
}