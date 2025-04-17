# README: Generating All Possible 5-Letter Words from Input File

This program reads a list of words from a file, processes them, and generates all possible 5-letter combinations from the characters of the words. The program uses recursion to achieve this and employs efficient memory management to handle dynamic data. Below is a step-by-step guide to understanding and running the program.

---

## 1. **Purpose**
The program generates all possible 5-letter combinations using the characters of words provided in an input file. Each position in the 5-letter word corresponds to characters from a specific word in the input list.

---

## 2. **Input File Format**
The input file should be structured as follows:
1. The first line contains an integer `n`, representing the number of words in the file.
2. The subsequent `n` lines contain the words. Each word should be a single string without spaces.

**Example Input File**:
```
5
MEHRAN
HASSAN
SAEID
AMIRHOOSSEIN
SAJAD
```

---

## 3. **Program Workflow**
The program performs the following steps:

### Step 1: **Reading and Storing Words**
- The `read_and_store_file` function reads the words from the file and stores them in a dynamically allocated array of `struct words`.
- Each word is stored along with its length.

### Step 2: **Generating Combinations**
- The `multiplication_principle` function recursively generates all 5-letter combinations. It uses the following logic:
  - For each position (0 to 4), iterate through all characters of the corresponding word.
  - Append one character at a time to the solution array.
  - Proceed to the next position until all 5 positions are filled.
  - Print the resulting combination and continue.

### Step 3: **Memory Management**
- Memory is dynamically allocated for both the list of words and individual words.
- After processing, all allocated memory is freed to prevent memory leaks.

---

## 4. **Code Explanation**

### 4.1 **Structure Definition**
```c
typedef struct words list;
struct words {
    int len;
    char *word;
};
```
- `struct words` stores the length and the pointer to the actual word.

### 4.2 **Key Functions**
#### `list * read_and_store_file(char *file_name)`
- Reads the input file.
- Allocates memory for the list of words and their respective strings.
- Returns a pointer to the list of words.

#### `int multiplication_principle(list *list_of_word, char *sol, int count, int pos, int n)`
- Recursively generates all possible combinations of 5 characters.
- Parameters:
  - `list_of_word`: Array of words.
  - `sol`: Current solution (combination being built).
  - `count`: Count of generated combinations.
  - `pos`: Current position in the 5-letter word.
  - `n`: Target length of the word (fixed at 5).
- Returns the total count of generated combinations.

---

## 5. **How to Run the Program**

### Prerequisites
- A C compiler (e.g., GCC).
- Input file in the correct format.

### Steps
1. Save the code into a file, e.g., `word_generator.c`.
2. Prepare the input file (e.g., `file.txt`) with the structure described above.
3. Compile the program:
   ```bash
   gcc -o word_generator word_generator.c
   ```
4. Run the program:
   ```bash
   ./word_generator
   ```
5. The program will output all possible 5-letter combinations and display the total count.

---

## 6. **Example Output**
For the input file:
```
5
MEHRAN
HASSAN
SAEID
AMIRHOOSSEIN
SAJAD
```
The program will generate combinations such as:
```
MHSSA
MHSSA
MHSSA
...
```
And output the total count of combinations at the end.

---

## 7. **Error Handling**
- **File Not Found**: The program checks if the file exists and prints an error message if it doesn't.
- **Memory Allocation Failure**: The program verifies all memory allocations and prints an error message if any allocation fails.
- **Invalid Input**: If the input file format is incorrect, the program gracefully handles the error and exits.

---

## 8. **Memory Management**
- **Dynamically Allocated Memory**:
  - `list_of_word`: Frees memory for both the array and individual words.
  - `sol`: Frees memory for the solution array.
- Ensures no memory leaks occur during or after execution.

---

## 9. **Customization**
- To generate combinations of a different length, modify the `n` parameter in the `multiplication_principle` function call.
- Adjust the input file to include more or fewer words, ensuring the first line reflects the correct count.

---

## 10. **Conclusion**
This program demonstrates efficient use of recursion, dynamic memory allocation, and file handling in C. It serves as a practical example of solving combinatorial problems using basic programming constructs.

