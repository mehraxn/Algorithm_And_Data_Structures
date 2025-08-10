#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* highestFrequencyChar(char* str) {
    if (str == NULL || strlen(str) == 0) {
        return NULL;
    }

    int freq[256] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        freq[(unsigned char)str[i]]++;
    }

    int maxFreq = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int modeCount = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] == maxFreq) {
            modeCount++;
        }
    }

    char* result = (char*)malloc((modeCount + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] == maxFreq) {
            result[idx++] = (char)i;
        }
    }

    result[modeCount] = '\0';

    return result;
}

/*
  * We use an array of size 256 because it covers all possible values that can be stored
  * in a char data type. In C, char is typically 8 bits, which means it can represent
  * 2^8 = 256 different values (0 to 255). This includes all ASCII characters (0-127)
  * and extended ASCII characters (128-255). By using 256 as the array size, we ensure
  * that we can count the frequency of any character that might appear in the input
  * string, regardless of whether it's a standard ASCII character, extended ASCII,
  * or any other 8-bit character encoding. Each index in the array corresponds to
  * the ASCII value of a character, so freq[65] would store the count of 'A',
  * freq[97] would store the count of 'a', and so on.
  */
