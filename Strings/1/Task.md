# String to Matrix Converter

## Project Overview

This project implements a string parsing algorithm that converts a delimited string into a matrix structure. The program takes a string containing any characters (except periods) separated by periods and transforms it into a 2D matrix where each row represents a segment between delimiters.

## Problem Statement

Given a string containing any characters except periods and periods ('.') as separators, create a matrix where:
- Periods act as row delimiters
- Multiple consecutive periods are treated as a single delimiter
- Each resulting segment becomes a row in the matrix
- Rows can have different lengths

## Input Format

- **Type**: String
- **Content**: Any characters except periods
- **Separators**: One or more consecutive periods ('.')
- **Example**: `'a...dgdsafas.j.k..a.f'`

## Expected Output

A matrix (2D array) where:
- Each row contains characters from one segment
- Number of rows = number of valid segments
- Variable row lengths allowed
- Order of characters preserved within segments

## Example

**Input**: `'a...dgdsafas.j.k..a.f'`

**Expected Matrix Structure**:
```
Row 1: ['a']
Row 2: ['d', 'g', 'd', 's', 'a', 'f', 'a', 's']
Row 3: ['j']
Row 4: ['k']
Row 5: ['a']
Row 6: ['f']
```
*Total: 6 rows with varying lengths (1, 8, 1, 1, 1, 1)*

## Requirements

### Functional Requirements
1. Parse input string using periods as delimiters
2. Handle multiple consecutive periods as single separator
3. Ignore empty segments
4. Create matrix with variable row lengths
5. Preserve character order within segments

### Technical Requirements
1. Handle edge cases:
   - Empty input strings
   - Strings containing only periods
   - Strings with no periods
   - Leading/trailing periods
2. Efficient memory usage
3. Clear error handling
4. Comprehensive test coverage

## Implementation Guidelines

### Algorithm Considerations
- String splitting and parsing
- Dynamic array/list management
- Memory allocation for variable-length rows
- Edge case handling

### Performance Requirements
- Time complexity analysis required
- Space complexity documentation
- Scalability for large inputs



---

**Note**: Focus on creating a robust, well-tested solution that handles all edge cases gracefully while maintaining good performance characteristics.