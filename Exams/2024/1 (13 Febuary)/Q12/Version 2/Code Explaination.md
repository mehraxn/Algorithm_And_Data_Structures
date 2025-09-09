# README — Split an Alphanumeric String into Letter & Digit Queues (C)

This README explains a small C module that parses a string and splits it into **contiguous runs** of:

* lowercase letters (`'a'..'z'`) → pushed in order to a **letters** FIFO (queue)
* digits (`'0'..'9'`) → pushed in order to a **digits** FIFO (queue)

Each run is stored as a dynamically allocated string inside a singly linked list node. The function performs two passes over the same input: first to extract letter runs, then to extract digit runs.

> ❗️Scope: Only lowercase ASCII letters and decimal digits are recognized. All other characters (including uppercase letters and punctuation) act as *neutral separators*—they do not produce nodes and can “glue” runs together across them (details below).

---

## Table of Contents

1. [Quick Start](#quick-start)
2. [Data Structures](#data-structures)
3. [Public API](#public-api)
4. [How It Works (Step by Step)](#how-it-works-step-by-step)
5. [Examples](#examples)
6. [Complexity](#complexity)
7. [Memory Management](#memory-management)
8. [Portability Notes](#portability-notes)
9. [Design Choices & Edge Cases](#design-choices--edge-cases)
10. [Troubleshooting](#troubleshooting)

---

## Quick Start

### Demo `main.c`

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- declarations from the module ---
typedef struct node_s node_t;
struct node_s { char *letter; node_t *next; };

node_t *create_node(char *key);
void string_to_fifo(char *s, node_t **letter, node_t **digit);

static void print_list(const char *title, node_t *head) {
    printf("%s:\n", title);
    for (node_t *p = head; p; p = p->next) printf("  %s\n", p->letter);
}

static void free_list(node_t *head) {
    while (head) { node_t *n = head->next; free(head->letter); free(head); head = n; }
}

int main(void) {
    char input[] = "ab12cd003ef";
    node_t *letters = NULL, *digits = NULL;

    string_to_fifo(input, &letters, &digits);

    print_list("Letters", letters);   // expected: ab, cd, ef
    print_list("Digits", digits);     // expected: 12, 003

    free_list(letters);
    free_list(digits);
    return 0;
}
```

### Build

```bash
gcc -std=c11 -Wall -Wextra -O2 main.c your_module.c -o demo
./demo
```

On MSVC (Windows), see the **Portability Notes** regarding `strdup` and VLAs.

---

## Data Structures

```c
typedef struct node_s node_t;
struct node_s {
    char *letter;   // dynamically allocated C-string holding a run
    node_t *next;   // next element in the FIFO
};
```

* Each node stores **one run** (either letters or digits) as a NUL-terminated string.
* Both the letters queue and the digits queue are singly linked lists where new nodes are appended at the tail to preserve input order (FIFO behavior).

---

## Public API

### `node_t *create_node(char *key);`

Allocates a node and duplicates the null-terminated `key` string into `node->letter` using `strdup`. Sets `node->next = NULL` and returns the node pointer.

> The caller owns the returned node and must eventually free both `node->letter` and `node`.

### `void string_to_fifo(char *s, node_t **letter, node_t **digit);`

Parses the input string `s` **twice**:

1. **Pass 1** builds/extends the **letters** queue referenced by `*letter`, extracting contiguous runs of `'a'..'z'`.
2. **Pass 2** builds/extends the **digits** queue referenced by `*digit`, extracting contiguous runs of `'0'..'9'`.

If `*letter` or `*digit` are non-`NULL` upon entry, new nodes are appended to the existing tails. If they are `NULL`, the function initializes the head pointers.

Parameters are **double pointers** so the function can initialize the heads when the first node is created.

---

## How It Works (Step by Step)

Below is a paraphrased walk-through of the implementation logic.

### 1) Local state

```c
node_t *head_string = *letter; // current head for letters
node_t *head_string_temp = head_string; // tail pointer for letters

char *temp = s;                // remember original start
char temp_string[strlen(s)+1]; // buffer for the current run (VLA)
int counter = 0;               // number of chars in the buffer
```

* `temp_string` acts as a scratch buffer that accumulates the current run.
* `counter` tracks how many characters have been buffered.

### 2) First pass — collect letter runs

Pseudocode view:

```
for each char c in s:
  if c is digit:
    if counter>0: terminate buffer → create node → append to letters; reset counter
    else: continue
  else if c is lowercase letter:
    push c into buffer
  advance s
end

if counter>0: flush final buffered run into a node
```

Key nuances:

* Hitting a **digit** means a letter run (if any) is complete → *flush* it.
* Any other character (e.g., punctuation, uppercase) **does not flush** the buffer; it simply gets skipped and the loop continues. This means such characters *do not break a run* by themselves (they behave like neutral glue).

### 3) Second pass — collect digit runs

* Reset `s = temp` and `counter = 0`.
* Mirror of the first pass, but inverted: letters trigger a flush; digits are accumulated.
* Same neutral behavior for all non-letter, non-digit characters.

### 4) Appending nodes (FIFO)

Whenever a run is flushed:

```c
temp_string[counter] = '\0';
node_t *next_move = create_node(temp_string);
if (tail == NULL) { head = tail = next_move; *head_param = head; }
else { tail->next = next_move; tail = next_move; }
```

Appending at the tail preserves the original left-to-right order of runs → FIFO semantics.

---

## Examples

### Example 1

Input: `"ab12cd003ef"`

* **Letters queue:** `"ab" → "cd" → "ef"`
* **Digits queue:** `"12" → "003"`

### Example 2 (neutral characters)

Input: `"a-b_c99d"`

* Non-letter/digit characters (`-`, `_`) are neutral and **do not flush** buffers.
* **Letters:** one merged run `"abcd"`
* **Digits:** one run `"99"`

### Example 3 (uppercase & punctuation)

Input: `"ABCx..yZ10!20"`

* Only lowercase letters are recognized. `x` and `y` count; `ABC` and `Z` are neutral.
* Dots and `!` are neutral as well.
* **Letters:** `"xy"`
* **Digits:** `"10" → "20"`

---

## Complexity

* **Time:** `O(n)` where `n = strlen(s)`, with a small constant factor (two linear passes).
* **Space:** `O(k)` for the total length of all extracted runs (each duplicated with `strdup`) plus `O(m)` for `m` nodes.

---

## Memory Management

Because `create_node` duplicates run strings, you must free them:

```c
void free_list(node_t *head) {
    while (head) {
        node_t *next = head->next;
        free(head->letter);
        free(head);
        head = next;
    }
}
```

> Always free both queues after use to avoid leaks.

---

## Portability Notes

1. **`strdup`** is POSIX. On some platforms (e.g., MSVC) use `_strdup`, or provide a fallback:

   ```c
   #ifndef _MSC_VER
   #  define xstrdup strdup
   #else
   #  define xstrdup _strdup
   #endif
   ```

   Then replace `strdup` with `xstrdup`.

2. **Variable Length Arrays (VLAs)** like `char temp_string[strlen(s)+1];` are a C99 feature and are not supported by MSVC. A portable alternative is to allocate dynamically:

   ```c
   size_t n = strlen(s);
   char *temp_string = malloc(n + 1);
   // ... use then free(temp_string)
   ```

3. **Character set**: The code assumes ASCII and ignores locale/Unicode. If you need Unicode letter/digit classification, use appropriate libraries or `ctype.h` with care (still locale-limited) and extend logic.

---

## Design Choices & Edge Cases

* **Two-pass design** keeps each pass simple and avoids interleaving logic for two output queues.
* **Neutral separators**: Any character outside `'a'..'z'` and `'0'..'9'` does **not** cause a flush. This can *merge* runs across punctuation/uppercase. If you instead want punctuation to *break* runs, add an `else` branch that flushes when `counter>0`.
* **Empty input**: No nodes created; heads remain unchanged (likely `NULL`).
* **All digits or all letters**: Works; only the corresponding queue receives nodes.
* **Very long inputs**: With a VLA buffer, extremely long inputs may risk stack pressure; prefer heap allocation for robustness.
* **Allocation failures**: Current code assumes `malloc/strdup` succeed. For production, check for `NULL` and handle errors.

---

## Troubleshooting

* **No output in one of the queues**: Ensure your input actually contains the relevant class (letters/digits). Remember uppercase letters are ignored by design.
* **Unexpected merging across punctuation**: That’s by design (neutral separators). Modify the logic to flush on any non-matching character if you want stricter segmentation.
* **Compiler errors about `strdup`**: Include `<string.h>` (already done) and see the portability section for MSVC.
* **Warnings about VLAs**: Switch to dynamic allocation for `temp_string`.

---

## Appendix: Reference Implementation (for context)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s node_t;
struct node_s {
    char *letter;
    node_t *next;
};

node_t *create_node(char *key) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->letter = strdup(key);
    new_node->next = NULL;
    return new_node;
}

void string_to_fifo(char *s, node_t **letter, node_t **digit) {
    node_t *head_string = *letter;         
    node_t *head_string_temp = head_string;

    char *temp = s;                       
    char temp_string[strlen(s) + 1];
    int counter = 0;

    while (*s != '\0'){
        if (*s >= '0' && *s <= '9'){
            if (counter == 0) { s++; continue; }
            else {
                temp_string[counter] = '\0';
                node_t *next_move = create_node(temp_string);

                if (head_string_temp == NULL) {
                    head_string_temp = head_string = *letter = next_move;
                } else {
                    head_string_temp->next = next_move;
                    head_string_temp = next_move;
                }
                counter = 0;
            }
        }
        else if (*s >= 'a' && *s <= 'z'){
            temp_string[counter] = *s;
            counter++;
        }
        s++;
    }

    if (counter != 0){
        temp_string[counter] = '\0';
        node_t *next_move = create_node(temp_string);
        if (head_string_temp == NULL) {
            head_string_temp = head_string = *letter = next_move;
        } else {
            head_string_temp->next = next_move;
            head_string_temp = next_move;
        }
    }

    node_t *head_digit = *digit;
    node_t *head_digit_temp = head_digit;

    s = temp;
    counter = 0;

    while (*s != '\0'){
        if (*s >= 'a' && *s <= 'z'){
            if (counter == 0) { s++; continue; }
            else {
                temp_string[counter] = '\0';
                node_t *next_move = create_node(temp_string);

                if (head_digit_temp == NULL) {
                    head_digit_temp = head_digit = *digit = next_move;
                } else {
                    head_digit_temp->next = next_move;
                    head_digit_temp = next_move;
                }
                counter = 0;
            }
        }
        else if (*s >= '0' && *s <= '9'){
            temp_string[counter] = *s;
            counter++;
        }
        s++;
    }

    if (counter != 0){
        temp_string[counter] = '\0';
        node_t *next_move = create_node(temp_string);
        if (head_digit_temp == NULL) {
            head_digit_temp = head_digit = *digit = next_move;
        } else {
            head_digit_temp->next = next_move;
            head_digit_temp = next_move;
        }
    }
}
```
