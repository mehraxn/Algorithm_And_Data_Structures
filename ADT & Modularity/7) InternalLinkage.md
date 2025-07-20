# Internal Linkage in C - Detailed Explanation and Examples

## What is Internal Linkage in C?

In C, linkage refers to the visibility of variables and functions across different translation units (typically `.c` files).

**Internal linkage** means that a symbol (variable or function) is *visible only within the translation unit* (i.e., source file) in which it is defined. It cannot be accessed from other source files, even if linked together during compilation.

Internal linkage is specified by:

* The `static` keyword when applied to global (file-scope) variables and functions.

By contrast, **external linkage** means the symbol is accessible from other files using the `extern` keyword.

---

## Examples of Internal Linkage (10+ examples)

### Example 1: Static global variable

```c
// file1.c
#include <stdio.h>

static int counter = 0; // Only accessible within file1.c

void increment() {
    counter++;
    printf("Counter: %d\n", counter);
}

int main() {
    increment();
    increment();
    return 0;
}
```

### Example 2: Static function

```c
// file1.c
#include <stdio.h>

static void log_message() {
    printf("Logging internal message\n");
}

int main() {
    log_message();
    return 0;
}
```

### Example 3: Static const variable

```c
// file1.c
#include <stdio.h>

static const int max_value = 100;

int main() {
    printf("Max Value: %d\n", max_value);
    return 0;
}
```

### Example 4: Static array

```c
// file1.c
#include <stdio.h>

static int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void print_array() {
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main() {
    print_array();
    return 0;
}
```

### Example 5: Static function with forward declaration

```c
// file1.c
#include <stdio.h>

static void helper();

int main() {
    helper();
    return 0;
}

static void helper() {
    printf("Helper function\n");
}
```

### Example 6: Static function used in multiple places in the file

```c
// file1.c
#include <stdio.h>

static void print_debug() {
    printf("Debug info\n");
}

void main_func() {
    print_debug();
}

int main() {
    main_func();
    return 0;
}
```

### Example 7: Static inline function

```c
// file1.c
#include <stdio.h>

static inline int square(int x) {
    return x * x;
}

int main() {
    printf("Square of 4: %d\n", square(4));
    return 0;
}
```

### Example 8: Static variable used in multiple functions

```c
// file1.c
#include <stdio.h>

static int state = 1;

void use_state() {
    printf("State: %d\n", state);
}

int main() {
    use_state();
    return 0;
}
```

### Example 9: Static global pointer

```c
// file1.c
#include <stdio.h>

static char *message = "Hello";

int main() {
    printf("%s\n", message);
    return 0;
}
```

### Example 10: Static constant expression

```c
// file1.c
#include <stdio.h>

static const double pi = 3.14159;

int main() {
    printf("Pi: %.5f\n", pi);
    return 0;
}
```

### Example 11: Static variable shadowed by local variable

```c
// file1.c
#include <stdio.h>

static int count = 5;

void func() {
    int count = 10;
    printf("Local count: %d\n", count);
}

int main() {
    func();
    return 0;
}
```

---

## Examples that are NOT Internal Linkage (10 examples)

### Example 1: Global variable without static

```c
// file1.c
#include <stdio.h>

int counter = 0;

void increment() {
    counter++;
    printf("Counter: %d\n", counter);
}

int main() {
    increment();
    return 0;
}
```

### Example 2: Function without static

```c
// file1.c
#include <stdio.h>

void print_message() {
    printf("Hello\n");
}

int main() {
    print_message();
    return 0;
}
```

### Example 3: External declaration of a variable

```c
// file2.c
#include <stdio.h>

extern int counter;

int main() {
    printf("Counter: %d\n", counter);
    return 0;
}
```

### Example 4: Extern keyword on a function

```c
// file2.c
extern void print_message();

int main() {
    print_message();
    return 0;
}
```

### Example 5: Const global variable without static

```c
// file1.c
#include <stdio.h>

const int size = 100;

int main() {
    printf("Size: %d\n", size);
    return 0;
}
```

### Example 6: Function prototype without static

```c
// file1.c
#include <stdio.h>

int multiply(int a, int b);

int main() {
    printf("%d\n", multiply(3, 4));
    return 0;
}

int multiply(int a, int b) {
    return a * b;
}
```

### Example 7: Inline function without static

```c
// file1.c
#include <stdio.h>

inline int add(int a, int b) {
    return a + b;
}

int main() {
    printf("Sum: %d\n", add(2, 3));
    return 0;
}
```

### Example 8: Function declared and defined globally

```c
// file1.c
#include <stdio.h>

int divide(int x, int y) {
    return x / y;
}

int main() {
    printf("%d\n", divide(10, 2));
    return 0;
}
```

### Example 9: Global structure definition

```c
// file1.c
#include <stdio.h>

struct Point {
    int x, y;
};

int main() {
    struct Point p = {1, 2};
    printf("Point: (%d, %d)\n", p.x, p.y);
    return 0;
}
```

### Example 10: Variable declared in header (without static)

```c
// config.h
int config_flag;

// file1.c
#include <stdio.h>
#include "config.h"

int main() {
    config_flag = 1;
    printf("Config: %d\n", config_flag);
    return 0;
}
```

---

Let me know if you want to test or extend these examples in a real project!
