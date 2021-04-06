#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    float m;
    int n, y, w, x, z;
    
    do
    {
        m = get_float ("Change owed: ");
    }
    while (m < 0);
    
    int cents = round(m * 100);
    
    for (y = 0; cents >= 25; y++)
    {
        cents = (cents - 25);
    }
    for (w = 0; cents >= 10; w++)
    {
        cents = (cents - 10); 
    }
        
    for (x = 0; cents >= 5; x++)
    {
        cents = (cents - 5);
    }
    z = (cents - 1);

    n = (x + y + z + w);   
    
    printf("%i\n", n);
   
}