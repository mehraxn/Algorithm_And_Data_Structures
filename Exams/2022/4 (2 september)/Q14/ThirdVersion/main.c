#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void erase_duplicate (char *str) {

    int len = strlen(str);
    int i = 0, j = 0;

    char * temp = (char *)malloc((len+1) * sizeof(char));
    if (temp == NULL) {
        exit(0);
    }

    for (i = 0; i < len; i++) {
        int flag = 0;
        // Check if current character already exists in temp
        for (int k = 0; k < j; k++) {  // Check in temp up to j, not i
            if (temp[k] == str[i]) {
                flag = 1;
                break;  // Found duplicate, no need to continue
            }
        }

        if (flag == 0) {  // If NOT found (no duplicate)
            temp[j++] = str[i];  // Add to temp and increment j
        }
        // If flag == 1, skip this character (it's a duplicate)
    }

    temp[j] = '\0';  // Null terminate temp

    // Copy temp back to original string
    strcpy(str, temp);

    free(temp);  // Free allocated memory
    return;
}
