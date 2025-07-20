# Understanding External Linkage in C

## What is External Linkage?

In the C programming language, **linkage** defines the scope or visibility of identifiers (like variables or functions) across different translation units (source files).

### External Linkage:

An identifier with **external linkage** can be accessed from other files of the same program. By default:

* All global (file-scope) **variables** that are **not marked static** have external linkage.
* All **functions** (unless marked static) have external linkage.

### Internal Linkage:

If a global variable or function is declared with the `static` keyword, it has **internal linkage**, meaning it is restricted to the file it is declared in.

---

## Examples of External Linkage in C (More than 10 Examples)

### Example 1: Global Variable

```c
// file1.c
#include <stdio.h>

int count = 0; // External linkage

void printCount() {
    printf("Count: %d\n", count);
}
```

### Example 2: Global Function

```c
// file1.c
#include <stdio.h>

void printHello() {
    printf("Hello!\n");
} // External linkage

int main() {
    printHello();
    return 0;
}
```

### Example 3: Extern Declaration in Another File

```c
// file1.c
int count = 10;

// file2.c
#include <stdio.h>
extern int count; // Refers to 'count' declared in another file

int main() {
    printf("Count is: %d\n", count);
    return 0;
}
```

### Example 4: Header File Function Declaration

```c
// mylib.h
void add(int a, int b);

// mylib.c
#include <stdio.h>
#include "mylib.h"

void add(int a, int b) {
    printf("Sum: %d\n", a + b);
}

// main.c
#include "mylib.h"

int main() {
    add(2, 3);
    return 0;
}
```

### Example 5: Function Pointer Access Across Files

```c
// file1.c
#include <stdio.h>

void greet() {
    printf("Greetings!\n");
}

// file2.c
extern void greet();

void execute(void (*func)()) {
    func();
}

int main() {
    execute(greet);
    return 0;
}
```

### Example 6: Multiple Global Variables

```c
// file1.c
int x = 10, y = 20; // Both have external linkage

// file2.c
#include <stdio.h>
extern int x, y;

int main() {
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

### Example 7: Function Call Across Files

```c
// file1.c
#include <stdio.h>

void foo() {
    printf("foo called\n");
}

// file2.c
extern void foo();

int main() {
    foo();
    return 0;
}
```

### Example 8: Global Const Without static

```c
// file1.c
#include <stdio.h>

const int VALUE = 100; // External linkage by default

// file2.c
extern const int VALUE;

int main() {
    printf("Value: %d\n", VALUE);
    return 0;
}
```

### Example 9: Sharing Global Structs

```c
// file1.c
struct Data {
    int id;
};

struct Data globalData = {1}; // External linkage

// file2.c
#include <stdio.h>

extern struct Data globalData;

int main() {
    printf("ID: %d\n", globalData.id);
    return 0;
}
```

### Example 10: Shared Global Array

```c
// file1.c
int buffer[1024]; // External linkage

// file2.c
#include <stdio.h>
extern int buffer[];

int main() {
    buffer[0] = 42;
    printf("Buffer[0]: %d\n", buffer[0]);
    return 0;
}
```

### Example 11: Externally Defined Variables Only

```c
// file1.c
int data = 50;

// file2.c
#include <stdio.h>
extern int data;

int main() {
    printf("Data: %d\n", data);
    return 0;
}
```

---

## Examples of Non-External Linkage (Internal or No Linkage)

### Example 1: Static Global Variable

```c
// file1.c
#include <stdio.h>

static int counter = 0; // Internal linkage

void increment() {
    counter++;
    printf("Counter: %d\n", counter);
}

int main() {
    increment();
    return 0;
}
```

### Example 2: Static Function

```c
// file1.c
#include <stdio.h>

static void logMessage() {
    printf("Log\n");
} // Internal linkage

int main() {
    logMessage();
    return 0;
}
```

### Example 3: Local Variable in main()

```c
int main() {
    int local = 5; // No linkage
    printf("Local: %d\n", local);
    return 0;
}
```

### Example 4: Static Const Global

```c
// file1.c
#include <stdio.h>

static const int SIZE = 64; // Internal linkage

int main() {
    printf("Size: %d\n", SIZE);
    return 0;
}
```

### Example 5: Function with Local Variable

```c
void test() {
    int inner = 3; // No linkage
    printf("Inner: %d\n", inner);
}

int main() {
    test();
    return 0;
}
```

### Example 6: Block Scope Static

```c
void foo() {
    static int temp = 0; // No linkage (block scope)
    temp++;
    printf("Temp: %d\n", temp);
}

int main() {
    foo();
    foo();
    return 0;
}
```

### Example 7: Inline Function (C99+)

```c
#include <stdio.h>

inline void helper() { // No linkage by default unless extern is used
    printf("Help\n");
}

int main() {
    helper();
    return 0;
}
```

### Example 8: Typedef

```c
typedef int myInt; // No linkage

int main() {
    myInt a = 5;
    return 0;
}
```

### Example 9: Enum Constants

```c
enum State {ON, OFF}; // No linkage for ON, OFF

int main() {
    enum State s = ON;
    return 0;
}
```

### Example 10: Macro Definition

```c
#define PI 3.14159 // No linkage

int main() {
    double r = 2;
    double area = PI * r * r;
    return 0;
}
```

---

## Final Thoughts

Understanding linkage helps you manage the visibility and lifetime of variables and functions across files. Use **external linkage** when you need to share across files, and **internal or no linkage** when encapsulation is needed.

For modular and large-scale development, mastering linkage behavior is essential.
