#include <stdio.h>
#include <string.h>


void print_array_reverse_r(char *, int , int );
void print_array_reverse_r(char *array, int index, int size) {
    if (index >= size)
        return;  // Exits the function early when index >= size


    print_array_reverse_r(array, index + 1, size);  // Recursive call
    printf("%c ", array[index]);

    return;  // This is optional here!
}
