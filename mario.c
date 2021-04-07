#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column, wide, hash, gap;
    // Get Height from user between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    
    for (row = 0; row < height; row++)
    {
        wide = (row + height + 2);
        for (column = 0; column <= wide; column++)
        {
            hash = (row + column + 1);
            gap = (height);
            if (hash >= height && column != gap && column != (gap + 1))
            {
                printf("#");
            }
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
