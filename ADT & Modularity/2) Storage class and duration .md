# C Storage Class Specifiers

C provides four storage class specifiers that determine the scope, lifetime, and visibility of variables and functions. These are:

1. **Automatic (or `auto`)**
2. **Register**
3. **Extern**
4. **Static**

Each of these storage classes is used for specific purposes. Below is a detailed explanation with examples.

---

## 1. **Automatic (`auto`)**
- **Usage:** Only for variables, not for functions.
- **Scope:** Local to the block in which the variable is defined.
- **Lifetime:** The variable is created when the block is entered and destroyed when the block exits.
- **Default Behavior:** All local variables are `auto` by default.

### Example:
```c
#include <stdio.h>

void exampleAuto() {
    auto int x = 10; // Explicit use of 'auto' is optional
    printf("Value of x: %d\n", x);
}

int main() {
    exampleAuto();
    return 0;
}
```
- Output: `Value of x: 10`
- **Explanation:** The variable `x` is local to the `exampleAuto` function and cannot be accessed outside it.

---

## 2. **Register**
- **Usage:** Only for variables.
- **Scope:** Local to the block in which the variable is defined.
- **Lifetime:** Same as `auto` variables.
- **Purpose:** Suggests that the variable should be stored in a CPU register for faster access (actual placement depends on the compiler).
- **Note:** Rarely used today due to modern compiler optimizations.

### Example:
```c
#include <stdio.h>

void exampleRegister() {
    register int counter;
    for (counter = 0; counter < 5; counter++) {
        printf("Counter: %d\n", counter);
    }
}

int main() {
    exampleRegister();
    return 0;
}
```
- Output:
```
Counter: 0
Counter: 1
Counter: 2
Counter: 3
Counter: 4
```
- **Explanation:** The `counter` variable is suggested to be stored in a CPU register, making loop iterations potentially faster.

---

## 3. **Extern**
- **Usage:** Used for variables and functions to specify external linkage.
- **Scope:** Global (available across multiple files).
- **Lifetime:** Exists throughout the program's execution.
- **Purpose:** Access variables or functions defined in another file.

### Example:
#### File1.c
```c
#include <stdio.h>

int globalVar = 42; // Defined in File1.c
```

#### File2.c
```c
#include <stdio.h>

extern int globalVar; // Declaration in File2.c

void exampleExtern() {
    printf("Value of globalVar: %d\n", globalVar);
}

int main() {
    exampleExtern();
    return 0;
}
```
- **Compilation:**
```
gcc File1.c File2.c -o program
```
- Output: `Value of globalVar: 42`
- **Explanation:** The `extern` keyword in `File2.c` tells the compiler that `globalVar` is defined elsewhere.

---

## 4. **Static**
- **Usage:** Used for both variables and functions.
- **Scope:**
  - For variables: Local variables persist across function calls.
  - For functions: Limits the scope of a function to the file it is defined in.
- **Lifetime:** Exists throughout the program’s execution.

### Example 1: Static Variables
```c
#include <stdio.h>

void exampleStatic() {
    static int count = 0; // Static variable retains its value across calls
    count++;
    printf("Count: %d\n", count);
}

int main() {
    exampleStatic();
    exampleStatic();
    exampleStatic();
    return 0;
}
```
- Output:
```
Count: 1
Count: 2
Count: 3
```
- **Explanation:** The `count` variable is initialized only once and retains its value between function calls.

### Example 2: Static Functions
#### File1.c
```c
#include <stdio.h>

static void exampleStaticFunction() {
    printf("This is a static function.\n");
}

void callStaticFunction() {
    exampleStaticFunction();
}
```

#### File2.c
```c
#include <stdio.h>

void callStaticFunction();

int main() {
    callStaticFunction();
    return 0;
}
```
- **Compilation:**
```
gcc File1.c File2.c -o program
```
- Output: `This is a static function.`
- **Explanation:** The `exampleStaticFunction` is not accessible in `File2.c` because it is declared as `static` in `File1.c`.

---

## Summary Table
| Storage Class | Scope                  | Lifetime                   | Purpose                                  |
|---------------|------------------------|----------------------------|------------------------------------------|
| `auto`        | Local to block         | Until block exits          | Default for local variables             |
| `register`    | Local to block         | Until block exits          | Suggests CPU register storage           |
| `extern`      | Global (cross-files)   | Entire program execution   | Share variables/functions across files  |
| `static`      | Local to file/block    | Entire program execution   | Persist values or limit function scope  |

---

By understanding these storage classes, you can write more efficient and well-structured C programs.

