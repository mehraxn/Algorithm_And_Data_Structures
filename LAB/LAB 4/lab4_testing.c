#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define myassert(actual, expected) \
    do { \
        if ((expected) == (actual)) { \
            printf("\u2713\n"); \
        } else { \
            printf("\u2717 Fail: %s != %s\n", #actual, #expected); \
        } \
    } while (0)

// FUNCTIONS TO BE IMPLEMENTED

// A.
int mult(int x, int y) {
        return -1;
}

// B.
void d2b(int d, int *b, int *n) {
        return;
}

// C.
int catalan(int n) {
        return -1;
}

// D.
int countSpaces(char *s) {
        return -1;
}

// E.
int isPalindrome(char *s, int l) {
        return -1;
}

// support functions, do not modify
int arraycompare(int *, int, char *);

int main() {
        printf("Testing A.\n");
        myassert( mult(113,456), 51528 );
        myassert( mult(0,598), 0 );
        myassert( mult(501,0), 0 );
        myassert( mult(0,0), 0 );
        myassert( mult(1,1111), 1111 );

        printf("\nTesting B.\n");
        int b[256]={0}; int n=0;
        myassert( (n=0,d2b(2,b,&n),   arraycompare(b,n,"10")), 0);
        myassert( (n=0,d2b(35,b,&n),  arraycompare(b,n,"100011")), 0);
        myassert( (n=0,d2b(255,b,&n), arraycompare(b,n,"11111111")), 0);
        myassert( (n=0,d2b(256,b,&n), arraycompare(b,n,"100000000")), 0);
        myassert( (n=0,d2b(0,b,&n),   arraycompare(b,n,"0")), 0);

        printf("\nTesting C.\n");
        myassert( catalan(0), 1);
        myassert( catalan(3), 5);
        myassert( catalan(6), 132);
        myassert( catalan(16), 35357670);

        printf("\nTesting D.\n");
        myassert( countSpaces("hello world"), 1);
        myassert( countSpaces("hello\t\tworld"), 2);
        myassert( countSpaces("\nhello\t\tworld\r"), 4);
        myassert( countSpaces("\nh e\vl\nl  o\t\twor  \rld\r"), 12);

        printf("\nTesting E.\n");
        myassert( isPalindrome("abcba", 5), 1);
        myassert( isPalindrome("aaaa", 4), 1);
        myassert( isPalindrome("a", 1), 1);
        myassert( isPalindrome("ab", 2), 0);
        myassert( isPalindrome("aaba", 4), 0);
}

int arraycompare(int *array, int n, char *ref) {
        if( n != strlen(ref) )
                return -1;
        for( int i = n-1; i >= 0 ; i--) {
                if( array[i] != ref[n-i-1] - '0')
                        return -1;
        }
        return 0;
}
