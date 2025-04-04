#include <stdio.h>
#include <string.h>

#define L 100 // Define a constant for the length of character arrays
#define DIM 100 // Define a constant for the temporary input arrays

// Definition of the student structure
struct student {
    char s1[L], s2[L]; // Two character arrays to store student details
    int i;             // Integer variable for storing a student's integer data
    float f;           // Floating-point variable for storing a student's float data
};

// Function to read data into the student structure
void my_read(struct student *v) {
    char s1[DIM], s2[DIM]; // Temporary arrays to hold input values
    int i;
    float f;

    // Prompt the user to enter student details
    fprintf(stdout, "Enter student details (s1 s2 i f): ");

    // Read the details from standard input
    scanf("%s %s %d %f", s1, s2, &i, &f);

    // Copy the input values into the structure members
    strcpy(v->s1, s1);
    strcpy(v->s2, s2);
    v->i = i;
    v->f = f;

    return; // Return from the function
}

int main() {
    struct student v; // Declare a student structure variable

    // Call the function to read data into the structure
    my_read(&v);

    // Print the details of the student to verify correctness
    printf("Student details: %s %s %d %.2f\n", v.s1, v.s2, v.i, v.f);

    return 0; // End of program
}

/*
Explanation of Functions:
1. Structure Definition (`struct student`):
   - The `student` structure is defined to store information about a student, including two character arrays (`s1` and `s2`), an integer (`i`), and a floating-point number (`f`).

2. Function `my_read(struct student *v)`:
   - This function is used to read data into the `student` structure. It takes a pointer to a `student` structure as an argument.
   - Temporary arrays (`s1`, `s2`) and variables (`i`, `f`) are used to read the input values.
   - The function prompts the user to enter the student details, reads the values from input, and copies them into the structure pointed to by `v`.

3. Main Function (`main()`):
   - The `main` function declares a `student` structure variable (`v`), calls the `my_read` function to populate it, and then prints the entered student details to verify that the function worked correctly.

This program demonstrates how to use structures and pointers in C to modify data within a structure, emphasizing the use of pointers to pass data by reference.
*/
