#include <stdio.h>
#include <cs50.h>

//prints a double half-pyramid like the one in the old Mario game

int main(void)
{
    int height;

    //prompt user for height with constraints
    do
    {
        height = get_int("Please specify the height of double pyramid desired (0<x<=23): ");
    }
    while (height < 0 || height >= 24);

    //print double half-pyrimad
    for (int r = 0; r < height; r++)
    {
        //print spaces before each row to left-align the bottom-left corner of the left-hand half-pyramid
        for (int i = 0; i < height - (r + 1); i++)
        {
            printf(" ");
        }

        //print left-hand half-pyramid
        for (int c = 0; c < r + 1; c++)
        {
            printf("#");
        }

        //print two-space gap
        printf("  ");

        //print right-hand hald-pyramid
        for (int c = 0; c < r + 1; c++)
        {
            printf("#");
        }

        printf("\n");
    }
}