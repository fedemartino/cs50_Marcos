#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long creditCard, resto, decimal, i;
    int digitoB, digitoC, sumaPar, sumaBC, dobleDigito, digitoPar, digitoImpar;
    // ??????
    long h;
    int sumaImpar, condicionA, condicionB, condicionC, checkSum;

    do
    {
        creditCard = get_long("Number: ");
    }
    while (creditCard < 1);

    for (i = 10; i <= creditCard ; i = i * 100)
    {
        resto = (creditCard % (i * 10));
        decimal = resto - (creditCard % i);
        digitoPar = (decimal / i);
        dobleDigito = (digitoPar * 2);
        digitoB = (dobleDigito % 10);
        digitoC = ((dobleDigito - digitoB) / 10);
        sumaBC = digitoB + digitoC;
        sumaPar = sumaPar + sumaBC;

        if (i == 1000000000000000)
        {
            if (digitoPar == 4)
            {
               condicionA = 1;
            }
            else if (digitoPar == 5)
            {
              condicionA = 2;
            }
        }
        else if (i == 10000000000000 && (digitoPar == 7 || digitoPar == 4))
        {
            condicionC = 3;
        }
    }
    for (h = 1; h <= creditCard; h = h * 100)
    {
        resto = (creditCard % (h * 10));
        decimal = resto - (creditCard % h);
        digitoImpar = (decimal / h);
        sumaImpar = sumaImpar + digitoImpar;

        if (h == 100000000000000)
         {
             if (digitoImpar == 3)
             {
                 condicionA = 3;
             }
             if (digitoImpar >= 1 && digitoImpar <= 5)
             {
                 condicionB = 2;
             }
         }
        if (h == 1000000000000 && digitoImpar == 4)
        {
            condicionA = 1;
        }

    }
    printf("%i\n", sumaPar);
    printf("%i\n", sumaImpar);

    checkSum = sumaPar + sumaImpar;

   if (checkSum % 10 == 0)
   {
       if (condicionA == 1)
       {
            printf("VISA\n");
       }
       else if (condicionA == 2 && condicionB == 2)
       {
           printf("Master Card\n");
       }
       else if (condicionA == 3 && condicionC == 3)
       {
           printf("American Express\n");
       }
       else
       {
           printf("INVALID\n");
       }
    }
   else
   {
       printf("INVALID\n");
   }

}