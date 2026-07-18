#include <stdio.h>

void url_encode(char *str, int true_length) {
    int i, spaceCount = 0;

    // Count spaces
    for (i = 0; i < true_length; i++) {
        if (str[i] == ' ')
            spaceCount++;
    }

    // New length after replacement
    int newLength = true_length + (spaceCount * 2);

    // Null terminate the string
    str[newLength] = '\0';

    // Work backwards
    for (i = true_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength -= 3;
        } else {
            str[newLength - 1] = str[i];
            newLength--;
        }
    }
}

int main() {
    char str[50] = "Hello World";   // Extra buffer is available

    url_encode(str, 11);

    printf("%s\n", str);

    return 0;
}
