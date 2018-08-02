#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//this program encrypts a message using Caesar's algorithm ( i.e. c = (p + k) mod 26 )

int main(int argc, string argv[])
{
    //the program takes only one number (key)
    if (argc != 2)
    {
        printf("Please enter only one command-line argument (one key).\n");
        return 1;
    }

    //convert that string number to an integer equivalent
    string key_string = argv[1];

    int value = 0;
    int key = 0;
    for (int i = 0, length = strlen(key_string); i < length; i++)
    {
        value = (key_string[i] - '0') * pow(10, length - i - 1);
        key = key + value;
    }

    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");

    //use Caesar's algorithm
    for (int i = 0, length = strlen(plain); i < length; i++)
    {
        char letter = plain[i];

        if (isupper(letter))
        {
            int letter_pos = letter - 'A' + 1;
            int new_letter_pos = (letter_pos + key) % 26;
            printf("%c", 'A' + new_letter_pos - 1);
        }

        else if (islower(letter))
        {
            int letter_pos = letter - 'a' + 1;
            int new_letter_pos = (letter_pos + key) % 26;
            printf("%c", 'a' + new_letter_pos - 1);
        }

        else
            printf("%c", letter);
    }
    printf("\n");
    return 0;
}