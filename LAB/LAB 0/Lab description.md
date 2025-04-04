# Algorithms and Data Structures Laboratory 00

## Overview
This laboratory introduces fundamental concepts in algorithms and data structures through two practical exercises that involve file processing, data storage, and simple algorithms for sorting and counting. The exercises provide hands-on experience with C programming, focusing on:

- File I/O operations
- String manipulation
- Data structures (arrays and structures)
- Sorting algorithms
- Basic text processing

## Exercise 01: Word Frequency Counter

### Problem Statement
The exercise involves processing two files:
1. A text file with an undefined number of rows (each row < 100 characters)
2. A words file containing a list of words (each word < 20 characters, maximum 100 words)

The goal is to count the number of occurrences of each word from the second file in the text stored in the first file, treating capital and small letters as equivalent.

### Requirements
- Each file must be read only once
- Case insensitivity: "word", "WORD", and "WoRd" are considered equivalent
- The program must output each word with its absolute frequency

### Example

#### First file (text):
```
Watch your thoughts ; they become words .
Watch your words ; they become actions .
Watch your actions ; they become habits .
Watch your habits ; they become character .
Watch your character ; it becomes your destiny .
Lao-Tze
```

#### Second file (words):
```
watch
words
become
```

#### Expected Output:
```
watch - 5 occurrence(s)
words - 2 occurrence(s)
become - 4 occurrence(s)
```

### Observation
The exercise notes that the number of words in the second file is unknown, suggesting students should consider different data structure options for storing them. Additional options will be introduced during the course.

## Exercise 02: Rectangle Sorter

### Problem Statement
This exercise involves processing a file containing rectangle definitions and creating two output files with rectangles sorted by different criteria.

#### Input File Format
- Each rectangle is defined by two rows in the file
- Each row contains a 4-character string identifier followed by two real numbers (x and y coordinates of a vertex)
- The two rows define opposite vertices of the rectangle (either top-right and bottom-left OR top-left and bottom-right)
- The rows defining a single rectangle are not necessarily consecutive
- The maximum number of rectangles is 100

### Requirements
The program must:
1. Take three file names as command-line arguments:
   - Input file containing rectangle specifications
   - First output file for rectangles sorted by ascending area
   - Second output file for rectangles sorted by ascending perimeter
2. Process the input file to identify rectangles and calculate their areas and perimeters
3. Sort rectangles by the required criteria
4. Write the results to the corresponding output files

### Example

#### Command Line:
```
fileIn.txt fileArea.txt filePerimeter.txt
```

#### Input File (fileIn.txt):
```
rct2  1.5 3.5
xxyy  -0.5 3.0
xxyy  1.5 2.0
abcd  1.0 4.5
ktkr  -2.5 1.5
abcd  2.0 2.0
rct2  3.5 -2.0
trya  2.5 -1.0
ktkr  1.5 3.5
trya  4.0 4.0
```

#### Calculated Areas and Perimeters:
```
rct2   area=11.00   perimeter=15.00
xxyy   area= 2.00   perimeter= 6.00
abcd   area= 2.50   perimeter= 7.00
ktkr   area= 8.00   perimeter=12.00
trya   area= 7.50   perimeter=13.00
```

#### First Output File (fileArea.txt) - Sorted by Ascending Area:
```
xxyy
abcd
trya
ktkr
rct2
```

#### Second Output File (filePerimeter.txt) - Sorted by Ascending Perimeter:
```
xxyy
abcd
ktkr
trya
rct2
```

### Suggestion
The exercise suggests using an array of structures where each element stores:
- Rectangle name
- Coordinates of two extreme vertices

### Observation
Similar to Exercise 01, this exercise notes that the number of rectangles is undefined, prompting students to consider different data structure options, with the promise that more options will be introduced during the course.

## Implementation Considerations

### Exercise 01: Word Frequency Counter
For this exercise, students should consider:

1. **Data Structures:**
   - Array of strings to store words from the second file
   - Array of integers to store corresponding frequencies
   - Hash map (to be introduced later in the course) could be more efficient

2. **Algorithm:**
   - Read words from the second file into memory
   - Convert all words to lowercase for case-insensitive comparison
   - Process the text file line by line, extracting words and comparing with the stored list
   - Increment counters for each match found

3. **String Processing:**
   - Handling various delimiters in the text (spaces, punctuation)
   - Case conversion functions (e.g., `tolower()`)
   - Word extraction methods (considering special characters and punctuation)

### Exercise 02: Rectangle Sorter
For this exercise, students should consider:

1. **Data Structures:**
   - Array of structures, where each structure contains:
     - Rectangle identifier (4-character string)
     - Coordinates of vertices (two points, each with x and y values)
     - Calculated area and perimeter

2. **Algorithm:**
   - Parse the input file to extract rectangle data
   - Match pairs of vertices belonging to the same rectangle
   - Calculate area and perimeter for each rectangle
   - Sort rectangles by area for the first output file
   - Sort rectangles by perimeter for the second output file

3. **Geometry Calculations:**
   - Determining which vertices are opposite corners of a rectangle
   - Computing rectangle dimensions, area, and perimeter
   - Handling potential edge cases (e.g., invalid coordinates)

4. **Sorting:**
   - Implementing a sorting algorithm (e.g., bubble sort, insertion sort)
   - Sorting based on different criteria (area vs. perimeter)

## Conclusion
These laboratory exercises provide practical experience with fundamental concepts in algorithms and data structures, focusing on file I/O, data manipulation, and basic algorithm implementation. By completing these exercises, students will develop skills in:

- File processing
- Data structure design and implementation
- Algorithm development
- Problem-solving and analytical thinking

The observations about unknown quantities of data elements hint at more advanced data structures and algorithms that will be covered later in the course, encouraging students to think about scalability and efficiency in their solutions.