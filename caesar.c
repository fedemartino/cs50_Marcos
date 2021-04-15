#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }
    else
    {
        int arg_len = strlen(argv[1]);
        int key;

        for (int j = 0; j <= (arg_len - 1); j++)
        {
            if (argv[1][j] >= 48 && argv[1][j] <= 57)
            {
                key = atoi(argv[1]);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        printf("Success\n");
        string plaintext = get_string("Plaintext: ");

        int text_len = strlen(plaintext);

        printf("Ciphertext: ");
        for (int i = 0; i <= (text_len - 1); i++)
        {
            if (plaintext[i] <= 122 && plaintext[i] >= 97)
            {
                int m = (((plaintext[i] - 97) + key) % 26) + 97;
                printf("%c", (char) m);
            }
            if (plaintext[i] <= 90 && plaintext[i] >= 65)
            {
                int n = (((plaintext[i] - 65) + key) % 26) + 65;
                printf("%c", (char) n);
            }
            if (plaintext[i] > 122 || plaintext[i] < 65 || (plaintext[i] > 90 && plaintext[i] < 97))
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
}