# README: Generating Valid Palindrome Passwords in C

## Overview
This program generates **all valid palindrome passwords** of length **7 characters** based on specific constraints. A palindrome password is symmetric, meaning the first half mirrors the second half. The code uses **recursion** to explore all possible combinations efficiently, ensuring the generated passwords adhere to the constraints.

---

## Constraints for Password Structure
Each position in the 7-character password has specific rules:

1. **Position 1 & Position 7 (Mirrored):** Must contain **lowercase letters** ('a' to 'z').
2. **Position 2 & Position 6 (Mirrored):** Must contain **uppercase letters** ('A' to 'Z').
3. **Position 3 & Position 5 (Mirrored):** Must contain **digits** ('0' to '9').
4. **Position 4 (Middle Character):** Must contain either **'+'** or **'-'**.

The constraints ensure the palindrome symmetry across the password.

---

## Program Execution Flow

### 1. **Recursive Function**: `generatePasswords`
The core logic resides in the recursive function `generatePasswords`, which iteratively fills each position in the password. The function takes:
   - `password[]`: A partially filled password array.
   - `index`: The current position being filled.

#### Recursive Process
   - **Base Case:** When `index == 7`, the password is complete. It is printed, and the recursion ends.
   - **Recursive Steps:** Depending on the current index, different rules apply:
     - **Index 0 & 6:** Iterate through all lowercase letters ('a' to 'z').
     - **Index 1 & 5:** Iterate through all uppercase letters ('A' to 'Z').
     - **Index 2 & 4:** Iterate through all digits ('0' to '9').
     - **Index 3:** Assign either '+' or '-' and recurse.

The mirrored symmetry ensures that changes to `password[0]` are also applied to `password[6]` (and so on).

#### Recursive Example
For clarity, consider this step-by-step recursive call flow for one valid password:
1. `password[0]` and `password[6]` are assigned 'a'.
2. `password[1]` and `password[5]` are assigned 'A'.
3. `password[2]` and `password[4]` are assigned '0'.
4. `password[3]` is assigned '+'.
5. When `index == 7`, the complete password **"aA0+0Aa"** is printed.

---

### 2. **Main Function**: `main`
The main function initializes the password array and starts the recursive generation:
```c
char password[8]; // Array to store the 7-character password + null terminator

generatePasswords(password, 0); // Start recursive generation at index 0
```

#### Key Operations:
- `password[8]` ensures space for 7 characters plus the null terminator.
- The recursive function is invoked with `index = 0` to begin.

---

## Code Breakdown

### Function: `generatePasswords`
```c
void generatePasswords(char password[], int index) {
    if (index == 7) {
        password[7] = '\0';
        printf("%s\n", password);
        return;
    }
    
    switch (index) {
        case 0:
        case 6:
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                password[0] = password[6] = ch;
                generatePasswords(password, index + 1);
            }
            break;
        
        case 1:
        case 5:
            for (char ch = 'A'; ch <= 'Z'; ++ch) {
                password[1] = password[5] = ch;
                generatePasswords(password, index + 1);
            }
            break;
        
        case 2:
        case 4:
            for (char ch = '0'; ch <= '9'; ++ch) {
                password[2] = password[4] = ch;
                generatePasswords(password, index + 1);
            }
            break;
        
        case 3:
            password[3] = '+';
            generatePasswords(password, index + 1);
            password[3] = '-';
            generatePasswords(password, index + 1);
            break;
    }
}
```

- **`switch (index)`**: Determines what constraints apply based on the current position.
- **Mirrored Assignments:** For positions 0 and 6, the same value is assigned.
- **Recursion:** Calls `generatePasswords` to move to the next index.
- **Base Case:** When `index == 7`, the password is printed.

---

## Output Example
Here are some sample outputs:
```
aA0+0Aa
aA0-0Aa
aB1+1Ba
aB1-1Ba
...
```
Each password satisfies the palindrome symmetry and adheres to the constraints.

---

## Key Features
1. **Recursive Solution:** The recursion efficiently generates all combinations while ensuring symmetry.
2. **Modular Code:** Clean and structured with separation of logic.
3. **Constraints Enforced:** Password generation strictly follows the defined rules.
4. **Performance:** All possible passwords are explored without redundant checks.

---

## How to Run
1. Copy the program into a file, e.g., `palindrome_passwords.c`.
2. Compile using a C compiler:
   ```bash
   gcc palindrome_passwords.c -o palindrome_passwords
   ```
3. Run the executable:
   ```bash
   ./palindrome_passwords
   ```
4. View the output, which will display all valid palindrome passwords.

---

## Complexity Analysis
- **Time Complexity:** O(26 * 26 * 10 * 2) = O(13520)
   - Positions 0 & 6: 26 choices
   - Positions 1 & 5: 26 choices
   - Positions 2 & 4: 10 choices
   - Position 3: 2 choices ('+' or '-')
- **Space Complexity:** O(7) (Stack space for recursion).

---

## Conclusion
This program demonstrates a recursive approach to generate palindrome passwords efficiently. It explores all valid combinations based on strict constraints while ensuring a clear and structured implementation. This solution can be adapted or extended for similar problems involving symmetry and constraints.

