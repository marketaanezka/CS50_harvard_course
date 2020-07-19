#include <stdio.h>
#include <cs50.h>

int get_pyramid_height(void);
void build_pyramid(int);

int main(void)
{
    int n = get_pyramid_height();
    build_pyramid(n);

}

int get_pyramid_height(void)
{
    //we declare an integer
    int n;
    //we ask for an integer
    do
    {
        n = get_int("Height: ");
    }
    //and keep repeating it if integer is smaller than 1 or bigger than 0
    while (n < 1 || n > 8);

    return n;
}

void build_pyramid(int n)
{
    //cycle for the whole pyramid, repeated n times
    //gives us n lines
    for (int i = 0; i < n; i++)
    {
        //code for one line

        //cycle for first part of the line
        for (int j = i + 1; j <= n + i; j++)
            // if I use just j=i, I will have n+1 cycles
            //if I don't use n+i, each time I will have a shorter line
        {
            //in the first set of cycles (first line), j starts on 1. we want "#" on nth position, so we create a condition that checks if j is equal to n.
            //in the second (second line) set of cycles i is increased => j starts on 2. so as soon as j is equal or bigger than n, we print "#"
            if (j >= n)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        //gap
        printf("  ");

        //cycle for second half of pyramid
        for (int k = 0; k < n; k++)
            //here we only need to check the line number and based on the line number we print the number of "#" accordingly
        {
            if (k <= i)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}