# Understanding `pow()` and `minor()` Functions

## Table of Contents
1. [The `pow()` Function](#the-pow-function)
2. [The `minor()` Function](#the-minor-function)
3. [How They Work Together](#how-they-work-together)
4. [Visual Examples](#visual-examples)

---

## The `pow()` Function

### What is `pow()`?

The `pow()` function is a mathematical function from the `<math.h>` library that calculates powers (exponentiation).

**Function Signature:**
```c
double pow(double base, double exponent);
```

**Basic Usage:**
```c
pow(base, exponent) = base^exponent
```

### In Our Determinant Code

In our code, we specifically use:
```c
pow(-1, c)
```

**Purpose:** Generate alternating signs for the cofactor expansion

### How `pow(-1, c)` Works

| c value | Calculation | Result | Sign Pattern |
|---------|-------------|---------|--------------|
| 0       | (-1)^0     | +1      | Positive     |
| 1       | (-1)^1     | -1      | Negative     |
| 2       | (-1)^2     | +1      | Positive     |
| 3       | (-1)^3     | -1      | Negative     |
| 4       | (-1)^4     | +1      | Positive     |
| ...     | ...        | ...     | ...          |

**Pattern:** `+, -, +, -, +, -, ...`

### Why Do We Need Alternating Signs?

In cofactor expansion, the mathematical formula requires alternating signs:

**Mathematical Formula:**
```
det(A) = Σ a[0][j] × (-1)^(0+j) × M[0][j]
```

Where:
- `a[0][j]` = element in first row, column j
- `(-1)^(0+j)` = alternating sign factor
- `M[0][j]` = minor determinant

**Simplified (since we expand along row 0):**
```
det(A) = Σ a[0][j] × (-1)^j × M[0][j]
```

### Visual Example of Alternating Signs

For a 4×4 matrix expansion along the first row:

```
[a  b  c  d]     +a×minor  -b×minor  +c×minor  -d×minor
[e  f  g  h]  =     ↑         ↑         ↑         ↑
[i  j  k  l]    pow(-1,0) pow(-1,1) pow(-1,2) pow(-1,3)
[m  n  o  p]       = +1      = -1      = +1      = -1
```

### Alternative to `pow(-1, c)`

Instead of using `pow(-1, c)`, we could use:
```c
// More efficient alternatives:
int sign = (c % 2 == 0) ? 1 : -1;  // Using modulo
int sign = 1 - 2 * (c % 2);        // Mathematical trick
```

But `pow(-1, c)` is more mathematically explicit and easier to understand.

### Important Note About `pow()`

- `pow()` returns a `double` (floating-point number)
- In our integer context, it gets automatically converted to `int`
- For small integer exponents like our use case, this works perfectly
- Always remember to link the math library with `-lm` when compiling

---

## The `minor()` Function

### What is a Minor?

In linear algebra, a **minor** of a matrix is a smaller matrix created by removing one row and one column from the original matrix.

**Mathematical Definition:**
- For an n×n matrix A, the minor M[i][j] is the (n-1)×(n-1) matrix obtained by deleting row i and column j from A.

### Function Purpose

The `minor()` function creates these smaller matrices needed for cofactor expansion in determinant calculation.

### Function Signature

```c
void minor(
    int m[][MAX],    // Original matrix
    int i,           // Row to remove
    int j,           // Column to remove
    int n,           // Size of original matrix
    int m2[][MAX]    // Output: resulting minor matrix
);
```

### Step-by-Step Algorithm

Let's trace through the algorithm with a detailed example:

**Original 3×3 Matrix:**
```
Position: [0][0] [0][1] [0][2]
          [1][0] [1][1] [1][2] 
          [2][0] [2][1] [2][2]

Values:   [ 1 ]  [ 2 ]  [ 3 ]
          [ 4 ]  [ 5 ]  [ 6 ]
          [ 7 ]  [ 8 ]  [ 9 ]
```

**Goal:** Create minor by removing row 0, column 1 (remove row with [1,2,3], remove column with [2,5,8])

#### Algorithm Execution:

**Initialization:**
```c
int r, c, rr, cc;  // Loop variables
// rr, cc will track positions in the NEW matrix
```

**Outer Loop:** `for (rr = 0, r = 0; r < n; r++)`

| r | Check `r != i` (i=0) | Action | rr value |
|---|---------------------|---------|----------|
| 0 | `0 != 0` = FALSE   | Skip this row | 0 |
| 1 | `1 != 0` = TRUE    | Process row 1 | 0 |
| 2 | `2 != 0` = TRUE    | Process row 2 | 1 |

**When r = 1 (processing second row):**

Inner Loop: `for (cc = 0, c = 0; c < n; c++)`

| c | Check `c != j` (j=1) | Element | Action | New Position |
|---|---------------------|---------|---------|--------------|
| 0 | `0 != 1` = TRUE    | m[1][0] = 4 | Copy to m2[0][0] | cc = 1 |
| 1 | `1 != 1` = FALSE   | m[1][1] = 5 | Skip | cc stays 0 |
| 2 | `2 != 1` = TRUE    | m[1][2] = 6 | Copy to m2[0][1] | cc = 1 |

After processing row 1: `rr++` → rr = 1

**When r = 2 (processing third row):**

Inner Loop: `for (cc = 0, c = 0; c < n; c++)`

| c | Check `c != j` (j=1) | Element | Action | New Position |
|---|---------------------|---------|---------|--------------|
| 0 | `0 != 1` = TRUE    | m[2][0] = 7 | Copy to m2[1][0] | cc = 1 |
| 1 | `1 != 1` = FALSE   | m[2][1] = 8 | Skip | cc stays 0 |
| 2 | `2 != 1` = TRUE    | m[2][2] = 9 | Copy to m2[1][1] | cc = 1 |

**Final Result:**
```
Original Matrix:     Minor (remove row 0, col 1):
[1  2  3]           [4  6]
[4  5  6]    →      [7  9]
[7  8  9]
```

### Key Algorithm Features

1. **Row Skipping:** `if (r != i)` ensures we skip the row to be removed
2. **Column Skipping:** `if (c != j)` ensures we skip the column to be removed
3. **Index Mapping:** `rr` and `cc` track positions in the smaller matrix
4. **Dimension Reduction:** n×n matrix becomes (n-1)×(n-1) matrix

### Visual Representation of Minor Creation

**Example: Remove row 1, column 2 from a 4×4 matrix**

```
Original Matrix (4×4):
[a  b  c  d]
[e  f  g  h]  ← Remove this row
[i  j  k  l]
[m  n  o  p]
      ↑
   Remove this column

Resulting Minor (3×3):
[a  b  d]
[i  j  l]
[m  n  p]
```

### Memory Layout

The function works with static arrays, so:
- Original matrix uses positions [0][0] to [n-1][n-1]
- Minor matrix uses positions [0][0] to [n-2][n-2]
- Unused positions in arrays remain unchanged but are ignored

---

## How They Work Together

### In the Determinant Calculation

The `det()` function uses both functions in this sequence:

```c
for (c=0; c<n; c++) {
    minor(m, 0, c, n, tmp);                    // Create minor
    sum = sum + m[0][c] * pow(-1,c) * det(tmp,n-1);  // Apply cofactor formula
}
```

### Step-by-Step Integration

**For a 3×3 matrix expansion:**

1. **c = 0:**
   - `minor(m, 0, 0, n, tmp)` → Creates 2×2 minor removing row 0, col 0
   - `pow(-1, 0)` → Returns +1
   - `m[0][0] * (+1) * det(tmp, 2)` → Positive contribution

2. **c = 1:**
   - `minor(m, 0, 1, n, tmp)` → Creates 2×2 minor removing row 0, col 1  
   - `pow(-1, 1)` → Returns -1
   - `m[0][1] * (-1) * det(tmp, 2)` → Negative contribution

3. **c = 2:**
   - `minor(m, 0, 2, n, tmp)` → Creates 2×2 minor removing row 0, col 2
   - `pow(-1, 2)` → Returns +1  
   - `m[0][2] * (+1) * det(tmp, 2)` → Positive contribution

### Mathematical Relationship

The cofactor C[i][j] is defined as:
```
C[i][j] = (-1)^(i+j) × M[i][j]
```

Where:
- `M[i][j]` is the minor (created by `minor()` function)
- `(-1)^(i+j)` is the sign factor (created by `pow(-1, i+j)`)

In our code, we expand along row 0, so i=0:
```
C[0][j] = (-1)^(0+j) × M[0][j] = (-1)^j × M[0][j]
```

This is exactly what our code computes:
- `minor()` creates M[0][j]
- `pow(-1, c)` where c=j creates (-1)^j
- The product gives us the cofactor

## Visual Examples

### Complete 3×3 Example

**Matrix:**
```
[1  2  3]
[4  5  6]
[7  8  9]
```

**Expansion: det(A) = 1×C[0][0] + 2×C[0][1] + 3×C[0][2]**

**C[0][0]:** `pow(-1,0) = +1`, `minor(0,0)` = 
```
[5  6]  → det = 5×9 - 6×8 = -3
[8  9]
```
**Contribution:** `1 × (+1) × (-3) = -3`

**C[0][1]:** `pow(-1,1) = -1`, `minor(0,1)` = 
```
[4  6]  → det = 4×9 - 6×7 = -6  
[7  9]
```
**Contribution:** `2 × (-1) × (-6) = +12`

**C[0][2]:** `pow(-1,2) = +1`, `minor(0,2)` = 
```
[4  5]  → det = 4×8 - 5×7 = -3
[7  8]  
```
**Contribution:** `3 × (+1) × (-3) = -9`

**Final Result:** `-3 + 12 + (-9) = 0`

This demonstrates how `pow()` provides the correct signs and `minor()` creates the necessary submatrices for accurate determinant calculation.