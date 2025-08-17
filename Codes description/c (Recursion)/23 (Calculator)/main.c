#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int evaluate(char *s, int *index) {
    int result = 0;
    int sign = 1;
    int num = 0;

    while (s[*index] != '\0') {
        char c = s[*index];

        if (isdigit(c)) {

            num = num * 10 + (c - '0');
        } else if (c == '+') {

            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {

            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {

            (*index)++;
            num = evaluate(s, index);
        } else if (c == ')') {

            result += sign * num;
            return result;
        }


        (*index)++;
    }


    result += sign * num;
    return result;
}


int calculate(char *s) {
    int index = 0;
    return evaluate(s, &index);
}