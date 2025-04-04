#include <stdio.h>
#include <stdbool.h>

#define MAX_ID 10  // Maximum size of the universe (0 to 9)

// Direct Access Table (DAT)
bool attendance[MAX_ID];

void markAttendance(int id) {
    if (id >= 0 && id < MAX_ID) {
        attendance[id] = true;  // Mark student as present
    } else {
        printf("Invalid ID: %d\n", id);
    }
}

void displayAttendance() {
    printf("Student Attendance:\n");
    for (int i = 0; i < MAX_ID; i++) {
        printf("Student ID %d: %s\n", i, attendance[i] ? "Present" : "Absent");
    }
}

int main() {
    // Initialize all entries to false (all students are absent initially)
    for (int i = 0; i < MAX_ID; i++) {
        attendance[i] = false;
    }

    // Mark attendance for some students
    markAttendance(3);
    markAttendance(5);
    markAttendance(8);

    // Display attendance
    displayAttendance();

    return 0;
}
