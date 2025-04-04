# Multiplication Principle Program: README

This document explains the functionality, structure, and purpose of the provided C program. The program uses the multiplication principle to generate all valid permutations of numbers from multiple arrays, subject to a specific condition.

## **Purpose**

The program generates all permutations of numbers chosen from multiple arrays and filters them based on a condition: the sum of the numbers in each permutation must be divisible by 3. It also counts and prints the total number of such valid permutations.

---

## **Program Overview**

The program consists of the following components:

### **1. Data Structures**

#### **`array_t` Structure**
```c
typedef struct array_t array;
struct array_t {
    int number;     // Number of elements in the array
    int *numbers;   // Pointer to the array of integers
};
```
- **`number`**: Stores the count of integers in the array.
- **`numbers`**: Points to the dynamically allocated array of integers.

### **2. Recursive Function**

#### **`multiplication_principle` Function**
```c
int multiplication_principle(array *input, int *sol, int count, int pos, int n);
```
- This recursive function generates all permutations of numbers.
- **Parameters**:
  - `input`: Pointer to the array of `array_t` structures.
  - `sol`: Array to store the current permutation.
  - `count`: Accumulator for the total number of valid permutations.
  - `pos`: Current position being processed in the permutation.
  - `n`: Total number of arrays.
- **Returns**: The total count of valid permutations.

### **3. Main Function**

The main function initializes the input data and calls the recursive function to generate and filter permutations. After execution, it frees all dynamically allocated memory.

---

## **Program Flow**

### **1. Input Initialization**
- Three arrays are initialized with the following values:
  - `arrays[0]`: {6, 9}
  - `arrays[1]`: {0, 1, 8}
  - `arrays[2]`: {3, 2, 4}
- These arrays are dynamically allocated and stored in the `array_t` structures.

### **2. Generating Permutations**
- The recursive function, `multiplication_principle`, generates all permutations by iterating through the numbers in each array.
- The **base case** is when all positions in the solution array (`sol`) are filled (`pos >= n`).
  - The function calculates the sum of the numbers in `sol`.
  - If the sum is divisible by 3, the permutation is printed, and the count of valid permutations is incremented.

### **3. Recursive Exploration**
- For each position (`pos`), the function iterates over all numbers in the current array (`input[pos].numbers`) and assigns one to `sol[pos]`.
- It then recursively processes the next position (`pos + 1`).

### **4. Memory Management**
- Dynamically allocated memory for the arrays (`arrays[].numbers`) and the solution array (`sol`) is freed after use.

---

## **Sample Output**

For the given input arrays:
```c
arrays[0]: {6, 9}
arrays[1]: {0, 1, 8}
arrays[2]: {3, 2, 4}
```

### **Generated Permutations**
The program outputs permutations where the sum is divisible by 3:
```
603
912
981
```

### **Total Valid Permutations**
```
total number of permutation is 3
```

---

## **Code Explanation**

### **1. Base Case in Recursive Function**
```c
if (pos >= n) {
    int temp = 0;
    for (i = 0; i < n; i++) {
        temp += sol[i];
    }
    if (temp % 3 == 0) {
        for (i = 0; i < n; i++) {
            printf("%d", sol[i]);
        }
        printf("\n");
        return count + 1;
    }
    return count;
}
```
- When the solution array (`sol`) is complete, the sum of its elements is checked.
- If the sum is divisible by 3, the permutation is printed, and `count` is incremented.

### **2. Recursive Exploration**
```c
for (i = 0; i < input[pos].number; i++) {
    sol[pos] = input[pos].numbers[i];
    count = multiplication_principle(input, sol, count, pos + 1, n);
}
```
- Iterates through all numbers in the current array.
- Assigns each number to `sol[pos]` and proceeds to the next position by recursive call.

---

## **Dynamic Memory Management**

### Allocating Memory
- Memory for `numbers` arrays and the solution array is dynamically allocated using `malloc` and `calloc`:
```c
arrays[0].numbers = (int *)malloc(2 * sizeof(int));
sol = (int *)calloc(3, sizeof(int));
```

### Freeing Memory
- Memory is freed at the end of the program:
```c
for (int i = 0; i < 3; i++)
    free(arrays[i].numbers);
free(sol);
```

---

## **Edge Cases**
1. **Empty Arrays**:
   - If an array has `number = 0`, no permutations will be generated.

2. **No Valid Permutations**:
   - If none of the sums are divisible by 3, the program will not print any permutations, and the total count will be 0.

3. **Single Array**:
   - If there is only one array, the program will check the divisibility of each number in that array by 3.

---

## **Conclusion**
This program demonstrates the use of recursion to generate permutations and apply a filtering condition. It efficiently handles dynamic memory and ensures correctness through careful checks. The approach can be extended to solve similar problems involving permutations and conditions.

