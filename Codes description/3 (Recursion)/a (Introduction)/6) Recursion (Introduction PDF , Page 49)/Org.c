#include <stdio.h>
#define MAX 100

// Function to reverse print a string recursively
void reverse_print(char *s) {
    if (*s == '\0') {
        return;
    }
    reverse_print(s + 1);
    printf("%c", *s);
    return;
}

// Main function to get user input and call reverse_print
int main() {
    char str[MAX + 1];
    printf("Input string: ");
    scanf("%s", str);
    printf("Reverse string is: ");
    reverse_print(str);
    printf("\n");
    return 0;
}
