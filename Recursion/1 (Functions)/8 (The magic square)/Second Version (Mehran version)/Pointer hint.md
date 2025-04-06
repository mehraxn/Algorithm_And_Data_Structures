# Pointer Assignment and Modification in C

## Key Concept

When you pass a pointer (like an array) to a function in C, you can:

- ✅ Modify the contents it points to (e.g., change values of the array)
- ❌ NOT change where the pointer itself points (i.e., you can't reassign it like `ptr = other_array` and expect the change to reflect in the caller)

To change the pointer itself, you must pass a **pointer to a pointer**.

---

## Simple Code Example

```c
#include <stdio.h>

void modify_contents(int *arr) {
    arr[0] = 10; // ✅ This works! Changes original array
}

void reassign_pointer(int *arr) {
    static int new_data[3] = {100, 200, 300};
    arr = new_data; // ❌ This does NOT change original pointer
}

void reassign_pointer_correctly(int **arr) {
    static int new_data[3] = {100, 200, 300};
    *arr = new_data; // ✅ This changes original pointer in main()
}

int main() {
    int data[3] = {1, 2, 3};
    int *ptr = data;

    modify_contents(ptr);
    printf("After modify_contents: %d\n", ptr[0]); // prints 10

    reassign_pointer(ptr);
    printf("After reassign_pointer: %d\n", ptr[0]); // still prints 10 (no change)

    reassign_pointer_correctly(&ptr);
    printf("After reassign_pointer_correctly: %d\n", ptr[0]); // prints 100

    return 0;
}
```

---

## Summary

| Action                       | What You Need to Pass | Effect in Caller |
|-----------------------------|------------------------|------------------|
| Change array contents       | `int *ptr`             | ✅ Works         |
| Change the pointer itself   | `int *ptr`             | ❌ Doesn’t work  |
| Change the pointer itself   | `int **ptr`            | ✅ Works         |

