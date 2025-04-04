# Password Generation Task with Constraints

## Task Description
You need to generate all possible **passwords** given three lists of characters, but with an additional constraint:

1. You have **three lists** of characters.
2. A password is formed by selecting **one character from each list**.
3. **Constraint:** The password **must not contain two consecutive vowels**.

## Example Input
```
List 1: ['A', 'B', 'C']
List 2: ['O', 'D', 'E']
List 3: ['X', 'I', 'Y']
```

## Example Output (Valid Passwords Only)
```
B O X
B O Y
B D X
B D I
B D Y
B E X
B E Y
C O X
C O Y
C D X
C D I
C D Y
C E X
C E Y
```
(Note: Any combination where two consecutive vowels appear is removed.)

## Invalid Examples
```
A O X  (Invalid: 'A' and 'O' are consecutive vowels)
A E Y  (Invalid: 'A' and 'E' are consecutive vowels)
C O I  (Invalid: 'O' and 'I' are consecutive vowels)
```

### What is Meant by "Two Consecutive Vowels"?
A **consecutive vowel** means that two vowels appear right next to each other in the password. Vowels include: `A, E, I, O, U`. If any two of these are adjacent in a password, that password is considered **invalid**.

## Requirements
- Ensure that no generated password contains **two consecutive vowels**.
- Print only **valid passwords** that follow the constraint.
- Count and display the **total number of valid passwords**.

## Implementation Hints
- Define a function `is_vowel(char ch)` to check if a character is a vowel (`A, E, I, O, U`).
- Use a recursive function to generate and validate passwords.
- Store characters temporarily in an array while building passwords.
- Filter out passwords that contain consecutive vowels before printing.

## Expected Learning Outcomes
✅ Understanding of combinatorial problems.  
✅ Implementation of **recursive algorithms** for combinatorial generation.  
✅ Introduction to **character classification (vowel vs. consonant)**.  
✅ Application of **constraints in combinatorial problems**.  

### Bonus Challenge
Modify the program to allow a **variable number of lists** instead of exactly three lists. The program should work for any number of character lists provided.

---

Good luck! 🚀

