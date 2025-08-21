# Constraints of the Prefix Expression Evaluator (C Code)

This README explains the limitations and assumptions of the provided C function `eval_r`, which evaluates arithmetic expressions written in **prefix notation**.

---

## ✅ Capabilities

* Supports **prefix (Polish) notation** with operators before operands.
* Handles the binary operators: `+`, `-`, `*`, `/`.
* Operands can be real numbers (floats) with decimal points.
* Ignores whitespace between tokens.
* Can evaluate arbitrarily nested expressions (limited only by recursion depth).

---

## ⚠️ Constraints / Limitations

### 1. Binary operators only

Each operator must have **exactly two operands**.

* Works: `+ 1 2` → (1+2)
* Fails: `+ 1 2 3` (not supported because `+` is given 3 operands).

### 2. Unary minus not supported

Numbers cannot start with a `-` to represent negativity. For example:

* Fails: `-3.5` (interpreted as operator `-`, not a number)
* Workaround: `- 0 3.5` (equivalent to `0 - 3.5`).

### 3. Limited number format

* Supports only digits and decimal points (`12`, `45.6`).
* Does **not** support scientific notation (`1.2e3`) or explicit signs (`+5`, `-7.8`).

### 4. No error handling

* Malformed input (e.g., missing operands, unknown symbols) will cause undefined behavior.
* Division by zero is not checked and may cause runtime errors.

### 5. Recursion depth

* Deeply nested expressions may exceed the system’s recursion/stack limit and cause a crash.

---

## 🚀 Summary

This evaluator works reliably for **well-formed binary prefix expressions** with floats and the four basic operators. However, it does not support negative literals, n-ary operators, advanced number formats, or robust error checking.

---

### Example (works fine):

Prefix: `* + 5.3 12.1 3.7`
Infix: `(5.3 + 12.1) * 3.7`
Result: `64.38`

### Example (not supported):

Prefix: `+ 1 2 3`
Reason: `+` has three operands instead of two.
