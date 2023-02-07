#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get input from user
    long n = get_long("Number: ");

    //count the amount of integers from the number given when a positive number is inputed
    long amount = n;
    int count = 0;
    while (amount > 0)
    {
        amount = amount / 10;
        count++;
    }

    //if number given does not equate to a card number the print invalid
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //use modulus(%) and division(/) operators to get last and second last digit
    //declaration of integers as odd and even starting from the back to separate the two patterns
    int odd = 0;
    int even = 0;
    int mod_odd;
    int mod_even;
    long i = n;
    int sum = 0;

    //use do while loop to continue looping the calculation to get the subsequent patterns
    do
    {
        //modulus(%) of 10 returns the last digit in the string of numbers
        //repeat the calculation of modulus of 10 to get the subsequent odd and even numbers in the pattern
        mod_odd = i % 10;
        i = i / 10;
        odd = odd + mod_odd;

        mod_even = i % 10;
        i = i / 10;
        mod_even = mod_even * 2;
        even = even + (mod_even % 10) + (mod_even / 10);

    }
    while (i > 0);

    //add the final numbers in the calculation loop to get the final sum for the algorithm
    sum = even + odd;

    //if second digit does not equal to 0 then print invalid to avoid error
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //get firt two digits only (1-99)
    long j = n;
    do
    {
        j = j / 10;
    }
    while (j > 100);

    //if first digit is 4, then VISA
    if (j / 10 == 4)
    {
        printf("VISA\n");
    }

    //if first digit is 3 and second digit is either 4 or 7 then AMEX
    else if ((j / 10 == 3) && (j % 10 == 4 || j % 10 == 7))
    {
        printf("AMEX\n");
    }

    //if first digit is 5 and second digit is between 1 to 5 then MASTERCARD
    else if ((j / 10 == 5) && (j % 10 > 0 && j % 10 < 6))
    {
        printf("MASTERCARD\n");
    }

    //else print invalid to avoid error
    else
    {
        printf("INVALID\n");
        return 0;
    }
}