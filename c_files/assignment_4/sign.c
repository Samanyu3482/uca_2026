#include <stdio.h>


int sign(int x) {
    return (x >> 31) | (!!x);
}

int main() {
    int a = 130;
    int b = -23;
    int c = 0;

    printf("sign(%d) = %d\n", a, sign(a));
    printf("sign(%d) = %d\n", b, sign(b));
    printf("sign(%d) = %d\n", c, sign(c));

    return 0;
}