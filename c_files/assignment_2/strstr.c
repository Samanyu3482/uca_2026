#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    int i, j;

    // If needle is empty, return 0
    if (needle[0] == '\0')
        return 0;

    for (i = 0; haystack[i] != '\0'; i++) {
        j = 0;

        while (haystack[i + j] != '\0' &&
               needle[j] != '\0' &&
               haystack[i + j] == needle[j]) {
            j++;
        }

        // If we reached the end of needle, it is found
        if (needle[j] == '\0')
            return i;
    }

    return -1;
}

int main() {
    char haystack[] = "Embedded Systems";
    char needle[] = "bed";

    int index = find_substring(haystack, needle);

    printf("%d\n", index);

    return 0;
}
