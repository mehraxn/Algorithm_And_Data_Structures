#include <stdio.h>


double myPow(double , int);

int main(){

    return 0;
}





double myPow(double x, int n) {
        // Handle edge case where n is 0, as any number to the power of 0 is 1
        if (n == 0) {
            return 1.0;
        }

        // Handle negative powers by converting x to 1/x and making n positive
        long long N = n;  // Use long long to handle the edge case of n = -2^31
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double current_product = x;

        // Loop until all bits of N are processed
        while (N > 0) {
            // If N is odd, multiply the result by the current product
            if (N % 2 == 1) {
                result *= current_product;
            }
            // Square the current product and halve N
            current_product *= current_product;
            N /= 2;
        }

        return result;
    }
