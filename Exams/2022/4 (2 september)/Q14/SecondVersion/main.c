#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void erase_duplicate (char *str) {
    char * temp_string = str ;
    int write_pos = 0;  // Position to write characters

    while (*temp_string != '\0') {
        char *temp_string2 = str;
        int flag = 0;

        while (temp_string2 < temp_string) {  // Only check characters before current
            if (*temp_string2 == *temp_string) {
                flag = 1;  // Found duplicate before current position
                break;
            }
            temp_string2++;
        }

        if (!flag) {  // If no duplicate found before current position
            str[write_pos] = *temp_string;  // Keep this character
            write_pos++;
        }

        temp_string++;
    }

    str[write_pos] = '\0';  // Null terminate the result
}
