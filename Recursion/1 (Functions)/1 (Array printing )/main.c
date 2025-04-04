#include <stdio.h>
#include <string.h>


void print_array_r(char *, int , int );
void print_array_r(char *array, int index, int size) {
    if (index >= size)
        return;  // Exits the function early when index >= size

    printf("%c ", array[index]);
    print_array_r(array, index + 1, size);  // Recursive call

    return;  // This is optional here!
}
