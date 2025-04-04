The task is to implement a basic calculator that evaluates a given mathematical expression represented
as a string and returns the computed result. The expression may contain integers, addition (+),
subtraction (-), parentheses (( and )), and spaces. You cannot use any built-in functions, such as eval(),
to evaluate the expression directly. Instead, you must implement the logic yourself to properly parse and
compute the result.

The calculator needs to handle the following:

Addition and Subtraction are the primary operations allowed.

Parentheses are used to alter the order of evaluation, ensuring the correct sequence of operations.

Unary minus (-) is allowed to negate values, which means expressions like -5 or -(3 + 2) are valid.

The given input will be a valid expression, so there are no unexpected symbols or consecutive operators that you need to handle.

Examples:

Input: "1 + 1"
Explanation: Here, the expression adds 1 and 1, resulting in 2.
Output: 2


Input: " 2-1 + 2 "
Explanation: The expression computes 2 - 1 which is 1, then adds 2, resulting in 3.
Output: 3

Input: "(1+(4+5+2)-3)+(6+8)"
Explanation:
Start by evaluating the expression inside the innermost parentheses: 4 + 5 + 2, which results in 11.
Now, the expression becomes: 1 + 11 - 3 + (6 + 8).
Evaluating further, 1 + 11 - 3 results in 9.
Adding 6 + 8 results in 14.
Finally, 9 + 14 results in 23.
Output: 23



Key Constraints:
The length of the string s can be up to 300,000 characters, which means that your solution should be efficient both in terms of time
and space complexity.

The string consists of digits, operators (+, -), parentheses ((, )), and spaces.

Every number and every intermediate calculation will fit within the range of a signed 32-bit integer.
The challenge is to correctly parse and evaluate the expression, respecting the precedence of operations and handling parentheses and
unary negation appropriately. An efficient solution may involve using data structures like stacks to manage the state as you parse through
the string.












ChatGPT can make mistakes. Check important info.
