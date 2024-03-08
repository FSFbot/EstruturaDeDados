#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int length = strlen(str);
    char reversed[length+1];

    for(int i = 0; i < length; i++) {
        reversed[i] = str[length-i-1];
    }

    reversed[length] = '\0';

    printf("Reversed string is: %s", reversed);
}

int main() {
    char str[] = "Hello, World!";
    reverseString(str);
    return 0;
}
