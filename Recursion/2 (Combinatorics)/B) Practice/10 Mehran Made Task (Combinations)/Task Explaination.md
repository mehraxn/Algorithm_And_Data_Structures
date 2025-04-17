### README: Arrangement Generator Program

#### **Overview**
This program generates all possible **arrangements (permutations)** of a given array of integers without repetition. It utilizes recursion to generate arrangements of all sizes, from 1 to the size of the array. Each arrangement is printed, and the program calculates the total number of unique arrangements generated.

---

#### **Features**
1. Generate all possible arrangements (permutations) of a given array.
2. Handle arrangements of sizes ranging from 1 to the full size of the array.
3. Ensure no element is repeated in any arrangement using markers.
4. Display the total number of unique arrangements.

---

#### **How It Works**
1. **Input**: A predefined array of integers is used as input. For example: `[3, 4, 5, 6, 7, 8]`.
2. **Process**:
   - The program recursively selects elements from the array while keeping track of used elements to avoid repetition.
   - Arrangements of different sizes (`k`) are generated, starting from size 1 up to the size of the array.
3. **Output**:
   - All generated arrangements are printed for each size.
   - The total number of unique arrangements is displayed at the end.

---

#### **Usage**
1. The array is predefined in the code.
2. The user can modify the array size and contents as needed.
3. Run the program to:
   - Print all arrangements for each size.
   - Display the total number of arrangements.

---

#### **Example Output**
For an input array `[3, 4, 5]`:

```
Arrangements of size 1:
3
4
5
Arrangements of size 2:
3 4
3 5
4 3
4 5
5 3
5 4
Arrangements of size 3:
3 4 5
3 5 4
4 3 5
4 5 3
5 3 4
5 4 3
The total number of different numbers we can make is 15
```

---

#### **Constraints**
1. The array size (`n`) must be a positive integer.
2. Each arrangement must use elements without repetition.
3. The program uses recursion for generating arrangements.

---

#### **Goal**
To explore all unique arrangements (permutations) of an array's elements, demonstrating recursive problem-solving techniques while tracking usage to prevent duplication.

