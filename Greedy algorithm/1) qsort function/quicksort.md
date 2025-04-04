### **README: `qsort` Function**

The `qsort` function is part of the C standard library (`stdlib.h`) and is used to sort arrays. It is a highly versatile sorting function that employs the **quick sort algorithm** under the hood.

---

### **Function Prototype**
```c
void qsort(void *base, size_t num, size_t size, int (*comparator)(const void *, const void *));
```

---

### **Parameters**
1. **`base`**:
   - A pointer to the first element of the array to be sorted.
   - This must be a `void*`, allowing `qsort` to work with arrays of any data type.

2. **`num`**:
   - The total number of elements in the array to be sorted.

3. **`size`**:
   - The size in bytes of each element in the array.
   - Typically determined using the `sizeof` operator.

4. **`comparator`**:
   - A pointer to a comparison function used to determine the order of elements.
   - The comparison function must have the following signature:
     ```c
     int comparator(const void *a, const void *b);
     ```
     - It takes two pointers to elements and returns:
       - A negative value if `a` is less than `b`.
       - `0` if `a` is equal to `b`.
       - A positive value if `a` is greater than `b`.

---

### **Usage Example**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(const void *a, const void *b) {
    // Cast void pointers to int pointers and dereference
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    return (int_a - int_b); // Ascending order
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using qsort
    qsort(arr, arr_size, sizeof(int), compare_ints);

    // Print the sorted array
    for (size_t i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

#### **Output**:
```
1 2 5 6 9
```

---

### **Sorting an Array of Strings**
To sort an array of strings, you need a comparator function that compares two strings using `strcmp`.

#### **Example**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *a, const void *b) {
    const char **str_a = (const char **)a;
    const char **str_b = (const char **)b;

    return strcmp(*str_a, *str_b); // Ascending order
}

int main() {
    const char *arr[] = {"apple", "orange", "banana", "grape", "pear"};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array of strings using qsort
    qsort(arr, arr_size, sizeof(char *), compare_strings);

    // Print the sorted array
    for (size_t i = 0; i < arr_size; i++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}
```

#### **Output**:
```
apple
banana
grape
orange
pear
```

---

### **Sorting an Array of Structures**
To sort an array of structures, you need a comparator function that compares a specific field of the structure. For example, consider sorting an array of `record` structures by their `id` field.

#### **Example**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} record;

int compare_records(const void *a, const void *b) {
    const record *rec_a = (const record *)a;
    const record *rec_b = (const record *)b;

    return (rec_a->id - rec_b->id); // Sort by id in ascending order
}

int main() {
    record arr[] = {{3, "Alice"}, {1, "Bob"}, {2, "Charlie"}, {4, "Dave"}};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array of structures using qsort
    qsort(arr, arr_size, sizeof(record), compare_records);

    // Print the sorted array
    for (size_t i = 0; i < arr_size; i++) {
        printf("ID: %d, Name: %s\n", arr[i].id, arr[i].name);
    }
    return 0;
}
```

#### **Output**:
```
ID: 1, Name: Bob
ID: 2, Name: Charlie
ID: 3, Name: Alice
ID: 4, Name: Dave
```

---

### **Behavior of the `comparator`**
The `comparator` function defines the sorting logic. For example:
- **Ascending Order**:
  ```c
  return (*(int*)a - *(int*)b);
  ```
- **Descending Order**:
  ```c
  return (*(int*)b - *(int*)a);
  ```
- **Custom Structures**:
  Sorting an array of custom structs based on a field:
  ```c
  typedef struct {
      int id;
      char name[20];
  } record;

  int compare_records(const void *a, const void *b) {
      const record *rec_a = (const record*)a;
      const record *rec_b = (const record*)b;

      return (rec_a->id - rec_b->id); // Sort by id in ascending order
  }
  ```

---

### **Example Use Case in the Activity Selection Problem**
In the context of the activity selection problem:
- The `qsort` function is used to sort activities by their `stop` time.
- The `comparator` might look like this:
  ```c
  int compare_stop_time(const void *a, const void *b) {
      const activity_t *act_a = (const activity_t*)a;
      const activity_t *act_b = (const activity_t*)b;

      return (act_a->stop - act_b->stop);
  }
  ```
- Sorting is then done as follows:
  ```c
  qsort(activities, num_activities, sizeof(activity_t), compare_stop_time);
  ```

---

### **Important Notes**
1. **Stability**:
   - `qsort` is **not guaranteed to be stable**, meaning equal elements might not retain their original order.

2. **Performance**:
   - Average Time Complexity: \(O(n \log n)\).
   - Worst-Case Time Complexity: \(O(n^2)\) (can be mitigated with proper pivot selection).

3. **Flexibility**:
   - The use of a custom comparator makes it adaptable to a wide range of sorting needs.

4. **Portability**:
   - Since `qsort` is part of the standard library, it is available across all C compilers that support the standard.

---

### **Conclusion**
The `qsort` function is a powerful, generic sorting tool in C. By defining a custom comparator, you can sort arrays of any data type according to any criterion. For structured data or specific sorting rules, it's an essential and efficient utility.

Additionally, `qsort` can be used to sort arrays of strings or custom structures, making it highly flexible and suitable for many different use cases.

