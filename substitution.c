#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key;

    // Check command-line argument condition
    if (argc == 2)
    {
        int argv_len = strlen(argv[1]);

        // Check Key validity (26 alphabetic chars && no duplicate && case-insensitive)
        if (argv_len == 26)
        {
            for (int i = 0; i <= 25; i++)
            {
                //Alphabetic condition
                if (tolower(argv[1][i]) >= 97 && tolower(argv[1][i] <= 122))
                {
                    for (int k = 0; k <= 25; k++)
                    {
                        //No duplicate condition
                        if (tolower(argv[1][i]) == tolower(argv[1][k]) && i != k)
                        {
                            printf("Error\n");
                            return 1;
                        }
                        else
                        {
                            key = argv[1];
                        }
                    }
                }
                else
                {
                    printf("Error\n");
                    return 1;
                }
            }
        }
        else
        {
            printf("Error\n");
            return 1;
        }
    }
    else
    {
        printf("Error\n");
        return 1;
    }

    //Prompt text from user
    string plaintext = get_string("plaintext: ");
    int text_len = strlen(plaintext);

    printf("ciphertext: ");

    //Substitute chars
    for (int j = 0; j <= (text_len - 1); j++)
    {
        //Substitute uppercase chars
        if (plaintext[j] >= 65 && plaintext[j] <= 90)
        {
            int m = plaintext[j] - 65;
            printf("%c", toupper(key[m]));
        }
        //Substitute lowercase chars
        if (plaintext[j] >= 97 && plaintext[j] <= 122)
        {
            int n = plaintext[j] - 97;
            printf("%c", tolower(key[n]));
        }
        //Substitute non-alphabetic chars
        if (plaintext[j] < 65 || plaintext[j] > 122 || (plaintext[j] > 90 && plaintext[j] < 97))
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}