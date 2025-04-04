# Invert String Function Task

### Problem Statement

Write the function:

```c
void invert_string(char *s1, char **s2);
```

The function receives an input string (`s1`) of unknown length and generates an output string (`s2`). Initially, `s2` is a `NULL` pointer. The input string `s1` consists only of uppercase letters.

The function must allocate the string `s2` dynamically and store the same letters as `s1`, but transform all strictly ascending subsequences of single characters into strictly descending subsequences in `s2`.

For example:

- If `s1` is:
  
  `A B C D D D Z Y X W E F G`

  The function should store into `s2` the following string:
  
  `D C B A D Z D Y X W G F E`

### Explanation

- The sequence `A B C D` is strictly ascending, so it must be transformed into `D C B A`.
- Similarly, the sequence `D Z` must be transformed into `Z D`, and so on.

### Requirements

- Use standard C libraries for implementation.
- Implement all personal utility functions as required.
- Modularize the program for clarity.
- Report a brief description of the data structure and the adopted logic in plain English.
- Unclear or overly complex solutions may be penalized in terms of final evaluation.

### Additional Notes

- The string `s2` must be dynamically allocated by the function.
- The input string `s1` will only contain uppercase English letters.

