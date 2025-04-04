# Understanding Global Variables in C

### Question
In the following code snippet, can we say that `a` is a global variable?

```c
#include <stdio.h>
#include <stdlib.h>

int a = 1023;

int main(){
    printf("%d ",a);
    return 0;
}
```

### Answer
Yes, in this code, `a` is a **global variable**. Here is why:

---

## Characteristics of Global Variables

### 1. **Declared Outside Any Function**
   - The variable `a` is declared outside of `main()` and any other functions. This makes it a **global variable**, as it exists in the global scope of the program.

### 2. **Scope**
   - A global variable is accessible from any function within the file where it is declared. For example, `a` can be accessed in `main()` and any other functions defined in the same file.

### 3. **Storage Class**
   - By default, variables declared outside of functions have the **`extern` storage class**, even if the `extern` keyword is not explicitly mentioned. This means the variable has a global scope and persists for the entire execution of the program.

---

## Example Explanation
In the given code:

```c
#include <stdio.h>

int a = 1023; // Global variable

int main() {
    printf("%d ", a); // Accessing the global variable
    return 0;
}
```

- The variable `a` is **global**, so it is accessible within `main()` and retains its value throughout the program's execution.
- It is initialized to `1023` at the time of declaration, and this value is stored in memory until the program terminates.

---

## Demonstration with Multiple Functions
To further illustrate that `a` is a global variable, consider the following modified program:

```c
#include <stdio.h>

int a = 1023; // Global variable

void printGlobalA() {
    printf("Value of a in another function: %d\n", a);
}

int main() {
    printf("Value of a in main: %d\n", a);
    printGlobalA();
    return 0;
}
```

### Output
```
Value of a in main: 1023
Value of a in another function: 1023
```

- **Explanation:** The variable `a` is accessible from both `main()` and `printGlobalA()` because it is a global variable.

---

## Key Points to Remember About Global Variables

1. **Scope:** Global variables are accessible across all functions within the file they are declared in.
2. **Lifetime:** They exist for the entire duration of the program.
3. **Initialization:**
   - If a global variable is not explicitly initialized, it is automatically initialized to `0` (for numeric types) or `NULL` (for pointers).
   - In this case, `a` is explicitly initialized to `1023`.
4. **Storage Class:** Global variables have the `extern` storage class by default.

---

### Additional Question
What will be the output of `a` in the following code?

```c
#include <stdio.h>
#include <stdlib.h>

int a = 1023;

int main(){
    a = 67;

    printf("%d ", a);

    return 0;
}
```

### Answer
#### Output:
```
67
```

#### Explanation:
- The variable `a` is a global variable initialized to `1023`. However, in the `main()` function, its value is updated to `67` using the statement `a = 67;`.
- When `printf` is called, it prints the updated value of `a`, which is `67`.
- Since `a` is a global variable, any modification to it in one part of the program is reflected across the entire program.

---

### Summary
In the given code, `a` is a global variable because it is defined outside any function, has global scope, and persists throughout the program's execution. It can be accessed and modified by any function within the same file.

