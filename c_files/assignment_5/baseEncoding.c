
#include <stdio.h>
#include <string.h>

const char base64Table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

void base64Encode(const char input[], char output[])
{
    int inputLength = strlen(input);
    int i = 0;
    int j = 0;

    while (i < inputLength)
    {
        unsigned char byte1 = input[i++];
        unsigned char byte2 = 0;
        unsigned char byte3 = 0;

        int remaining = inputLength - i + 1;

        if (remaining > 1)
            byte2 = input[i++];

        if (remaining > 2)
            byte3 = input[i++];

        
        output[j++] = base64Table[byte1 >> 2];

       
        output[j++] = base64Table[((byte1 & 0x03) << 4) |
                                  (byte2 >> 4)];

       
        if (remaining <= 1)
        {
            output[j++] = '=';
        }
        else
        {
            output[j++] = base64Table[((byte2 & 0x0F) << 2) |
                                      (byte3 >> 6)];
        }

       
        if (remaining <= 2)
        {
            output[j++] = '=';
        }
        else
        {
            output[j++] = base64Table[byte3 & 0x3F];
        }
    }

    output[j] = '\0';
}

int main()
{
    char input[1000];
    char output[2000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

   
    input[strcspn(input, "\n")] = '\0';

    base64Encode(input, output);

    printf("Base64: %s\n", output);

    return 0;
}


