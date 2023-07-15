#include <stdio.h>

int main(void)
{
    //Asking the user for the hight
    int hight;
    do
    {
        printf("Enter the hight : ");
        scanf("%d", &hight);
    }
    while (hight <= 0 || hight > 8);

    //for Rows
    for (int i = 0 ; i < hight ; i++)
    {
        int counter = hight - 1;
        //for Columns
        for (int j = i ; j >= 0 ; j--)
        {
            //For the space in the left
            while (counter > i)
            {
                printf(" ");
                counter -= 1;
            }
            printf("#");
        }
        printf("\n");
    }
}