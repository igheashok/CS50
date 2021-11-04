#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

// Checks Whether A JPG Starts In Current Buffer //
bool jpgChecker(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Check Input Usage //
    if (argc != 2)
    {
        printf("Usage: ./recover fileName\n");
        return 1;
    }

    // Input File Creation //
    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        printf("Could not open the input file!\n");
        return 1;
    }

    // Important Declarations //
    int fileNameCounter = 0;
    bool anyJPGfileOpen = false;
    BYTE buffer[512];
    FILE *output;

    // Reading Buffer of 512 Bytes From Card //
    while (fread(buffer, sizeof(512), 1, input))
    {

        if (jpgChecker(buffer))
        {
            if (anyJPGfileOpen)
            {
                fclose(output);
            }
            else
            {
                anyJPGfileOpen = true;
            }

            // Settings For File Name //
            char fileName[7];
            sprintf(fileName, "%03i.jpg", fileNameCounter);
            fileNameCounter++;

            // New File Creation //
            output = fopen(fileName, "w");
            if (!output)
            {
                printf("Unable to open file!");
                return 1;
            }
            fwrite(buffer, sizeof(512), 1, output);
        }
        else
        {
            if (anyJPGfileOpen)
            {
                // Continue Previous JPG File Writing //
                fwrite(buffer, sizeof(512), 1, output);
            }
        }
    }

    fclose(output);
    fclose(input);
}


bool jpgChecker(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
