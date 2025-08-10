#include <stdio.h>
#include <string.h>

typedef struct array {
    char *string;
} array;

int multiplication_principles(array *array1, char *solution, int n, int count, int pos) {
    int i;

    if (pos >= n) {
        solution[pos] = '\0';  // null-terminate
        printf("%s\n", solution);
        return count + 1;
    }

    for (i = 0; i < (int)strlen(array1[pos].string); i++) {
        solution[pos] = array1[pos].string[i];
        count = multiplication_principles(array1, solution, n, count, pos + 1);
    }

    return count;
}

int main() {
    array arr[7] = {
        {"ALI"},
        {"HASSAN"},
        {"MAHMOUD"},
        {"KARIM"},
        {"ASLAN"},
        {"MEHRAN"},
        {"HAMED"}
    };

    char solution[100]; // enough space for max length
    int total = multiplication_principles(arr, solution, 7, 0, 0);

    printf("Total combinations: %d\n", total);
    return 0;
}
