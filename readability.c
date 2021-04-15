#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

string abc = "abcdefghijklmnopqrstuvwxyz";

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;
    int text_len = strlen(text);
    int abc_len = strlen(abc);

    for (int i = 0; i <= text_len; i++)
    {
        for (int j = 0; j <= abc_len - 1; j++)
        {
            if (tolower (text[i]) == abc[j])
            {
                letters += 1;
            }
        }
        if (text[i] == ' ')
        {
            words += 1;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }
    }

    float perCwords = words / 100.00;

    float L = letters / perCwords;
    float S = sentences / perCwords;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}