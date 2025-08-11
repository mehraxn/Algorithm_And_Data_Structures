#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // for INT_MIN

// Counts the maximum number of times any prefix of 'string' appears in the string
int counter(char *string) {
    int final_counter = INT_MIN; // Changed MIN_INF → INT_MIN (standard constant)
    int len_str = strlen(string);
    char *temp = (char *)malloc((len_str + 1) * sizeof(char)); // fixed missing parenthesis

    for (int i = len_str - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++)
            temp[j] = string[j];
        temp[i + 1] = '\0';

        int count = 0;
        int len_temp = strlen(temp);
        for (int k = 0; k <= len_str - len_temp; k++) { // fixed 'len()' and added '<='
            int flag = 1;
            for (int z = 0; z < len_temp; z++) {
                if (string[k + z] != temp[z]) { // fixed index: compare from k
                    flag = 0;
                    break; // small optimization
                }
            }
            if (flag)
                count++;
        }

        if (count > final_counter)
            final_counter = count;
    }

    free(temp); // prevent memory leak
    return final_counter;
}

// Finds the row with the maximum prefix repeat count
void check(char **m, int n) {
    int counter_num = INT_MIN; // changed MIN_INT → INT_MIN
    int final_row = -1; // added missing semicolon
    char *temp = (char *)malloc((n + 1) * sizeof(char));
    int counter_temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            temp[j] = m[i][j];
        temp[n] = '\0'; // null-terminate row string

        counter_temp = counter(temp);
        if (counter_temp > counter_num) {
            counter_num = counter_temp;
            final_row = i; // fixed 'row' undeclared → use final_row
        }
    }

    printf("Row with max prefix repeats: %d (count = %d)\n", final_row, counter_num);

    free(temp); // prevent memory leak
}
