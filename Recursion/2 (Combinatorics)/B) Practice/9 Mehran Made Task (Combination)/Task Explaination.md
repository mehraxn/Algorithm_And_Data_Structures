# Generating Combinations with Repetition and Detecting Consecutive Vowels

## Problem Statement:

You are tasked with writing a program that generates all possible combinations of size \( k \) from a given set of characters (in this case, the English lowercase alphabet). The combinations allow repetition of characters. After generating each combination, the program should check if at least two vowels (from the set \( \{a, e, i, o, u\} \)) appear consecutively in the combination. If so, the combination should be printed, and the total count of such combinations should be calculated.

---

## Requirements:

1. **Vowel Checking:** Write a function to check if a character is a vowel.
2. **Consecutive Vowel Check:** Write a function to check if a given combination contains consecutive vowels.
3. **Recursive Combination Generation:** Use recursion to generate all possible combinations with repetition of size \( k \) from the alphabet.
4. **Printing and Counting:** Print each combination where consecutive vowels appear and count the total number of such combinations.

---

## Inputs:

- **Alphabet Size (\( n \)):** Fixed to 26 (representing the lowercase English alphabet \( \{a, b, c, \ldots, z\} \)).
- **Combination Size (\( k \)):** The size of the combinations to generate, which can be set dynamically (e.g., \( k = 5 \)).

---

## Outputs:

1. A list of all combinations of size \( k \) where at least two vowels appear consecutively.
2. The total number of such combinations.

---

## Example:

### Input:
- **Alphabet:** \( \{a, b, c, \ldots, z\} \)
- \( k = 5 \)

### Output:
```
The words that two vowels letters appear next to each other are:
aaabc
aaabd
aaabe
...
The total number of the words is: <count>
```

---

## Additional Notes:

- Ensure proper memory allocation and deallocation to avoid memory leaks.
- Use recursion to efficiently handle the generation of combinations.
- Allow the program to dynamically adjust for different values of \( k \) if needed.
- Make sure the solution is modular, with clear functions for each task (vowel checking, recursive combination generation, and printing/counting).

---

## Objectives of the Task:

This task emphasizes the following concepts in C programming:

1. **Recursive Programming:** Leveraging recursion to generate combinations efficiently.
2. **String Manipulation:** Working with characters and arrays to build and analyze combinations.
3. **Memory Management:** Dynamically allocating and freeing memory to handle combinations of varying sizes.
4. **Logical Reasoning:** Identifying and validating combinations based on specific criteria (consecutive vowels).

By completing this project, you will demonstrate your understanding of these fundamental programming techniques.

