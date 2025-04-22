# Recursion Types: Linear vs. Multiple Recursion

Recursion is a powerful programming technique in which a function calls itself to solve a problem. There are different types of recursion based on the structure of the recursive calls. Two common types are **Linear Recursion** and **Multiple Recursion**. This document explains their differences and provides clear examples to understand each type thoroughly.

## 1. Linear Recursion

In **Linear Recursion**, a function makes **only one** recursive call during its execution. The problem is reduced step by step into a smaller instance, and once the base case is reached, the recursive calls resolve in reverse order.

### Key Features:
- Only one recursive call per function call.
- Often used in problems like factorial, sum of array elements, etc.

### Example: Factorial Calculation
```python
# Linear Recursion

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

print(factorial(5))  # Output: 120
```

### Explanation:
- The function calls itself once per level (`factorial(n - 1)`).
- The recursion depth equals `n`, and each call resolves one by one as the base case is reached.

---

## 2. Multiple Recursion

In **Multiple Recursion**, a function makes **more than one** recursive call during its execution. Each call may branch into further recursive calls, forming a tree-like structure.

### Key Features:
- More than one recursive call per function call.
- Commonly used in problems like Fibonacci sequence, permutations, combinations, etc.

### Example: Fibonacci Sequence
```python
# Multiple Recursion

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

print(fibonacci(5))  # Output: 5
```

### Explanation:
- Each function call generates **two** recursive calls: `fibonacci(n - 1)` and `fibonacci(n - 2)`.
- This creates a binary tree of recursive calls, leading to exponential time complexity.

---

## Summary of Differences

| Feature               | Linear Recursion                | Multiple Recursion                     |
|----------------------|----------------------------------|----------------------------------------|
| Number of Calls      | One per function                | More than one per function             |
| Structure            | Straight (like a list)          | Tree-like branching                    |
| Time Complexity      | Usually linear (O(n))           | Often exponential (O(2^n), etc.)       |
| Use Cases            | Factorial, sum, search, etc.    | Fibonacci, permutations, combinations  |

---

Understanding the difference between linear and multiple recursion helps in writing more efficient recursive algorithms and choosing the appropriate structure for the problem at hand.

