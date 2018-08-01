#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//checks whether a credit card number is valid and prints what company the credit card is associated with

int llong_len();
int int_len();
string check_starting_numbs();

int main(void)
{
    int length = 0;
    long long ccnum = 0;

    ccnum = get_long_long("What is you're credit card number?: ");
    length = llong_len(ccnum);

    //check the length of the credit card number
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int digits[length];

    for (int i = length - 1; i >= 0; i--)
    {
        digits[i] = ccnum % 10;
        ccnum = floor(ccnum / 10);
    }

    //check if the number is associated to AMEX, VISA, or MASTERCARD
    string company = check_starting_numbs(digits);

    if (strcmp(company, "INVALID") == 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //use credit card checking algorithm to see if the number is legitimate
    int total_under = 0;
    int int_length = 0;
    for (int i = length - 2; i >= 0; i = i - 2)
    {
        digits[i] = digits[i] * 2;
        int_length = int_len(digits[i]);

        int a[length];
        int num = digits[i];
        for (int b = int_length - 1; b >= 0; b--)
        {
            a[b] = num % 10;
            total_under = total_under + a[b];
            num = num / 10;
        }
    }

    int total_other = 0;
    for (int i = length - 1; i >= 0; i = i - 2)
    {
        total_other = total_other + digits[i];

    }

    int total = total_under + total_other;

    if (total % 10 == 0)
    {
        printf("%s\n", company);
    }

    else
        printf("INVALID\n");

}

//gets the number of digits of a long long type number
int llong_len(long long n)
{
    if(n == 0)
    {
        return 0;
    }

    return floor(log10(llabs(n))) + 1;
}

//gets the number of digits of an integer type number
int int_len(int n)
{
     if(n == 0)
    {
        return 0;
    }

    return floor(log10(abs(n))) + 1;
}

//checks what (if any) company the number corresponds with
string check_starting_numbs(int a[])
{
    if (a[0] == 4)
    {
        return "VISA";
    }

    if ( (a[0] == 3 && a[1] == 4) || (a[0] == 3 && a[1] == 7) )
    {
        return "AMEX";
    }

    if (  a[0] == 5 && ( (a[1] >= 1) && (a[1] <= 5) )  )
    {
        return "MASTERCARD";
    }

    return "INVALID";
}