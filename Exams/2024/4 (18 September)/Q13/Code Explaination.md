# Switches and Bulbs Problem

## Overview
This program solves the problem of determining the minimum number of switches to press in order to turn on all the bulbs in a given configuration. Each switch can toggle certain bulbs, and the goal is to find the smallest set of switches that results in all bulbs being turned on.

The program takes as input a matrix where each row represents a switch and each column represents a bulb. A value of `1` in the matrix indicates that the corresponding switch toggles the state of the bulb, while a value of `0` means it does not affect the bulb.

---

## Code Details

### 1. **Main Function**

#### Purpose:
The `main` function initializes the switch-bulb matrix and calls the `switches` function to solve the problem.

#### Steps:
1. Define the number of switches and bulbs.
2. Allocate memory for the matrix dynamically.
3. Populate the matrix with example data.
4. Call the `switches` function to find the minimum set of switches to press.
5. Free the allocated memory to avoid memory leaks.

#### Example Matrix:
```c
int input[4][5] = {
    {1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 0, 0, 1, 0}
};
```
This represents 4 switches and 5 bulbs, where:
- Switch 0 toggles bulbs 0, 1, and 4.
- Switch 1 toggles bulbs 0 and 2, etc.

---

### 2. **Function: `switches`**

#### Purpose:
The `switches` function serves as the main driver to find the minimum set of switches to press.

#### Steps:
1. Calls `find_min_switch_set` to compute the optimal solution.
2. Outputs the result to the user.

---

### 3. **Function: `find_min_switch_set`**

#### Purpose:
This function evaluates all possible combinations of switches to find the smallest set that turns on all bulbs.

#### Steps:
1. Use a bitmask to represent all combinations of switches (2^`switch_count` possibilities).
2. For each combination:
   - Simulate the toggling of bulbs.
   - Count the number of switches pressed.
   - Check if all bulbs are turned on.
3. Track the combination with the minimum switches pressed that satisfies the condition.
4. Output the result:
   - Minimum number of switches to press.
   - Indices of the switches to press.

#### Key Variables:
- `combo`: Represents a combination of switches (e.g., `0110` means switches 1 and 2 are pressed).
- `bulbs[]`: Tracks the state of each bulb (on/off).
- `min_switches`: Stores the minimum number of switches needed.
- `best_combo`: Stores the bitmask of the optimal switch combination.

#### Complexity:
- Time complexity: O(2^`switch_count` * `bulb_count`)
- Space complexity: O(`bulb_count`)

---

### 4. **Function: `press_switch`**

#### Purpose:
Simulates the toggling of bulbs when a specific switch is pressed.

#### Steps:
1. Iterate over all bulbs.
2. If the bulb is controlled by the switch (matrix value is 1), toggle its state (on/off).

---

### 5. **Function: `all_bulbs_on`**

#### Purpose:
Checks if all bulbs are turned on.

#### Steps:
1. Iterate through the `bulbs` array.
2. Return `false` if any bulb is off, otherwise return `true`.

---

## Example Run

### Input:
Switch-bulb matrix:
```
1 1 0 0 1
1 0 1 0 0
0 1 1 1 0
1 0 0 1 0
```

### Output:
```
Minimum number of switches to press: 2
Switches to press: 0 2
```

---

## Memory Management
- The matrix is dynamically allocated to allow flexibility in the number of switches and bulbs.
- After computation, all allocated memory is freed to prevent memory leaks.

---

## Customization
1. Modify `switch_count` and `bulb_count` to change the problem size.
2. Replace the example matrix in `main` with a user-defined configuration.

---

## Limitations
- Exponential time complexity for a large number of switches.
- Assumes all switches are independent and no switch directly controls another switch.

---

## Conclusion
This program demonstrates an efficient approach to solving the minimum switch pressing problem using exhaustive search with bitmasking. While suitable for small to medium-sized inputs, it can be optimized further for larger configurations using heuristic or advanced algorithms.

