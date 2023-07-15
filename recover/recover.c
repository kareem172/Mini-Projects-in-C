#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t Byte;

int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    //Checking the user input
    if (argc != 2)
    {
        printf("Usage: ./recover card.row\n");
        return 1;
    }

    //open the memory and check if it is found
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("memory can't be found\n");
        return 1;
    }

    Byte buffer[512];        //declare the buffer to store the return of fread

    int is_first = 1;        //flag to indicate the first img

    int is_found = 0;        //flag to indicate if the start of jpg is found

    int file_num = 0;        //used in naming the images

    char img_name[100];

    FILE *img;
    // Repeat untill the end of the memory
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check the start of jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            is_found = 1;
            //Check the first jpg
            if (is_first)
            {
                is_first = 0;
            }
            else
            {
                fclose(img);
            }
            //Open new file to store the jpg./vlo
            sprintf(img_name, "%03i.jpg", file_num);
            img = fopen(img_name, "w");
            fwrite(buffer, 1, BLOCK_SIZE, img);
            file_num++;
        }
        else
        {
            if (is_found)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }
    }
    fclose(file);
    fclose(img);
    return 0;
}