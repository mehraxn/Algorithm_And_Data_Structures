## Understanding Permutations with Repetition:

### Definition:

Permutations with repetition occur when you have a set of objects, some of which are identical, and you need to determine how many distinct ways you can arrange them. This concept is crucial in combinatorics when dealing with multisets.

### Formula:

If you have **n** total objects where:

- α objects are identical,
- β objects are identical,
- γ objects are identical, etc.,

Then the number of distinct permutations is calculated as:

total permutations =\
\(P_n(\alpha, \beta, \gamma, ...) = \frac{n!}{\alpha! \beta! \gamma! ...}\)

### Explanation:

This formula accounts for the fact that swapping identical elements does not create a new unique arrangement, so we divide by the factorial of each repeated object's count to remove duplicate arrangements.

### Examples:

1. **Example 1: ARRANGEMENT OF LETTERS**

   - Given the word "MISSISSIPPI", where we have:
     - M = 1 time,
     - I = 4 times,
     - S = 4 times,
     - P = 2 times.
   - The number of distinct permutations is:
     \(\frac{11!}{1! 4! 4! 2!} = \frac{39916800}{24 \times 24 \times 2} = 34650\)

2. **Example 2: ARRANGING NUMBERS**

   - Consider the digits "122333", where:
     - 1 appears once,
     - 2 appears twice,
     - 3 appears three times.
   - The number of unique arrangements is:
     \(\frac{6!}{1! 2! 3!} = \frac{720}{1 \times 2 \times 6} = 60\)

3. **Example 3: ARRANGING OBJECTS**

   - A bag contains 7 balls labeled as {A, A, A, B, B, C, C}.
   - The distinct permutations are:
     \(\frac{7!}{3! 2! 2!} = \frac{5040}{6 \times 2 \times 2} = 210\)

##
