# Acronym Generator

## Overview
This program is designed to generate all valid acronyms from a list of strings read from an input file and write them to an output file. Each acronym is constructed by recursively combining characters from each input string and validating them according to specific rules.

The program works by:
1. Reading strings from an input file.
2. Generating all possible acronyms by recursively combining characters from the input strings.
3. Validating each acronym against a predefined set of rules.
4. Writing the valid acronyms to an output file.

## Features
- **Input/Output**: Reads input strings from a file and writes the valid acronyms to another file.
- **Recursive Acronym Generation**: Uses a recursive function to explore all possible combinations of characters.
- **Validation Rules**: Acronyms must alternate between letters and digits (starting with a letter).
- **Memory Management**: Allocates and frees memory dynamically to handle variable input sizes.

## Files
- **Input File**: The input file contains a list of strings to generate acronyms from.
- **Output File**: The output file contains all valid acronyms.

## Acronym Rules
An acronym is considered valid if:
1. Characters at even indices (0, 2, 4, ...) are letters (`A-Z`, `a-z`).
2. Characters at odd indices (1, 3, 5, ...) are digits (`0-9`).

For example:
- Valid: `A1B2`
- Invalid: `AB12`, `A123`, `1A2B`

## Code Details

### 1. **Main Function**
```c
int main() {
    const char *input_file = "input.txt";
    const char *output_file = "output.txt";

    // Call the acronym function
    acronym(input_file, output_file);

    printf("Acronyms have been generated and written to %s\n", output_file);
    return 0;
}
```
The `main` function initializes the input and output file names and calls the `acronym` function.

### 2. **Acronym Function**
```c
void acronym(const char *nameI, const char *nameO) {
    ...
}
```
This is the main function that coordinates the process:
1. Opens the output file.
2. Reads input strings using `read_input`.
3. Allocates memory for recursive acronym generation.
4. Calls `generate_acronyms` to generate and validate acronyms.
5. Frees memory and closes files.

### 3. **Reading Input**
```c
void read_input(const char *filename, char **strings, int *n) {
    FILE *input = fopen(filename, "r");
    if (!input) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    fscanf(input, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(input, "%s", strings[i]);
    }

    fclose(input);
}
```
This function reads the input file:
- The first line contains the number of strings (`n`).
- Subsequent lines contain the strings.

### 4. **Recursive Acronym Generation**
```c
void generate_acronyms(char **strings, int n, char *current_acronym, int index, FILE *output) {
    if (index == n) {
        if (is_valid_acronym(current_acronym)) {
            fprintf(output, "%s\n", current_acronym);
        }
        return;
    }

    for (int i = 0; i < strlen(strings[index]); i++) {
        current_acronym[index] = strings[index][i];
        generate_acronyms(strings, n, current_acronym, index + 1, output);
    }
}
```
This function generates acronyms recursively:
1. If all characters are selected (`index == n`), validate the acronym.
2. Iterate through all characters of the current string and append them to the acronym.
3. Recursively call the function for the next string.

### 5. **Validation**
```c
int is_valid_acronym(const char *acronym) {
    for (int i = 0; acronym[i] != '\0'; i++) {
        if (i % 2 == 0) {
            if (!isalpha(acronym[i])) {
                return 0;
            }
        } else {
            if (!isdigit(acronym[i])) {
                return 0;
            }
        }
    }
    return 1;
}
```
This function checks if an acronym satisfies the rules:
- Even indices must be letters.
- Odd indices must be digits.

## Input/Output Format

### Input File
The input file should have the following format:
```
<number_of_strings>
<string1>
<string2>
...
```
Example:
```
3
abc
123
def
```

### Output File
The output file will contain one valid acronym per line. Example:
```
a1d
a1e
a2d
a2e
...
```

## Example Execution
### Input (`input.txt`)
```
2
abc
12
```

### Output (`output.txt`)
```
a1
a2
b1
b2
c1
c2
```

### Command Line
Compile the program:
```bash
gcc -o acronym_generator acronym_generator.c
```
Run the program:
```bash
./acronym_generator
```

## Memory Management
The program dynamically allocates memory for:
- Strings read from the input file.
- Temporary storage for acronyms during recursive generation.

All allocated memory is freed before the program terminates to prevent memory leaks.

## Error Handling
- Checks if the input and output files can be opened.
- Exits gracefully with an error message if file operations fail.

## Extensions
- Add support for additional validation rules.
- Generate acronyms with custom patterns.
- Optimize memory usage for large inputs.

## Conclusion
This program provides a robust framework for generating and validating acronyms from an input file. The recursive approach ensures all combinations are explored, and the validation function enforces the required structure for acronyms.

