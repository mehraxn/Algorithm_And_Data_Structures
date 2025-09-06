#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student node (inner list)
typedef struct StudentNode {
    char student_name[50];
    struct StudentNode* next;
} StudentNode;

// Class node (main list)
typedef struct ClassNode {
    char class_name[50];
    int num_students;
    StudentNode* right;  // Points to list of students
    struct ClassNode* next;
} ClassNode;

/**
 * Function to print all classes and their students
 */
void print_classes_and_students(ClassNode* head) {
    if (head == NULL) {
        printf("No classes found.\n");
        return;
    }

    ClassNode* current_class = head;

    printf("=== CLASS AND STUDENT LIST ===\n\n");

    while (current_class != NULL) {
        // Print class information
        printf("Class: %s\n", current_class->class_name);
        printf("Number of Students: %d\n", current_class->num_students);
        printf("Students:\n");

        // Print student list in this class
        StudentNode* current_student = current_class->right;

        if (current_student == NULL) {
            printf("  (No students enrolled)\n");
        } else {
            int student_count = 1;
            while (current_student != NULL) {
                printf("  %d. %s\n", student_count, current_student->student_name);
                current_student = current_student->next;
                student_count++;
            }
        }

        printf("----------------------------------------\n");
        current_class = current_class->next;
    }
}

/**
 * Add a new class to the main list
 */
ClassNode* add_class(ClassNode* head, char* class_name, int num_students) {
    ClassNode* new_class = (ClassNode*)malloc(sizeof(ClassNode));
    strcpy(new_class->class_name, class_name);
    new_class->num_students = num_students;
    new_class->right = NULL;
    new_class->next = head;
    return new_class;
}

/**
 * Add a student to a specific class
 */
void add_student_to_class(ClassNode* classes, char* class_name, char* student_name) {
    ClassNode* current_class = classes;

    // Find the class
    while (current_class != NULL) {
        if (strcmp(current_class->class_name, class_name) == 0) {
            // Found the class, add student
            StudentNode* new_student = (StudentNode*)malloc(sizeof(StudentNode));
            strcpy(new_student->student_name, student_name);
            new_student->next = current_class->right;
            current_class->right = new_student;
            return;
        }
        current_class = current_class->next;
    }

    printf("Class '%s' not found!\n", class_name);
}

// Sample main function to test
int main() {
    ClassNode* classes = NULL;

    // Create some classes
    classes = add_class(classes, "Computer Science 101", 3);
    classes = add_class(classes, "Mathematics 201", 2);
    classes = add_class(classes, "Physics 301", 4);

    // Add students to Computer Science 101
    add_student_to_class(classes, "Computer Science 101", "Alice Johnson");
    add_student_to_class(classes, "Computer Science 101", "Bob Smith");
    add_student_to_class(classes, "Computer Science 101", "Charlie Brown");

    // Add students to Mathematics 201
    add_student_to_class(classes, "Mathematics 201", "David Wilson");
    add_student_to_class(classes, "Mathematics 201", "Eva Garcia");

    // Add students to Physics 301
    add_student_to_class(classes, "Physics 301", "Frank Miller");
    add_student_to_class(classes, "Physics 301", "Grace Lee");
    add_student_to_class(classes, "Physics 301", "Henry Taylor");
    add_student_to_class(classes, "Physics 301", "Ivy Chen");

    // Print all classes and students
    print_classes_and_students(classes);

    return 0;
}
