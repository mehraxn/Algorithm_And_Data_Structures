#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_string (char * s1 , char **s2){

    char * final_word=(char*)malloc((strlen(s1) + 1) * sizeof (char) );
    int j=0;
    int i =1;
    char * temp = s1;

    while (i< strlen(s1)){

        if (temp[i-1] < temp[i]){
            int start = i-1;                                    // ADDED: mark start of run
            while (i < strlen(s1) && temp[i-1] < temp[i] ) i++; // CHANGED: add bound check
            for (int k = i; k > start; )                        // CHANGED: correct reverse loop
                final_word[j++] = temp[--k];
            continue;
        }
        else {
            final_word[j++]=temp[i-1];   // CHANGED: should use i-1, not i
            i++;
        }
    }

    if (strlen(s1) > 0)                        // ADDED: last char copy
        final_word[j++] = temp[strlen(s1)-1];

    final_word[j] = '\0';                      // ADDED: terminate string
    *s2 = final_word;                          // CHANGED: return pointer instead of wrong loop
}
