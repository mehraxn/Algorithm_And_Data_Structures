# Complete Line-by-Line Analysis of Heap Implementation

This README provides a comprehensive, line-by-line explanation of a complete heap implementation in C, including visual illustrations and detailed algorithmic analysis.

## Code Structure Overview

The implementation consists of:
- **Macros**: For navigating the heap tree structure
- **Data Structure**: Heap representation using an array
- **Core Functions**: swap, heapify, build_heap, heapSort

---

## Line-by-Line Analysis

### Macro Definitions

```c
#define PARENT(i)  (((i)-1)>>1)
```
**Purpose**: Calculate the parent index of node at index `i`
- `(i)-1`: Subtract 1 from current index
- `>>1`: Right shift by 1 bit (equivalent to dividing by 2)
- **Formula**: Parent of node i = (i-1)/2
- **Example**: Parent of node 5 = (5-1)/2 = 2

```c
#define LEFT(i)    (((i)<<1)+1)
```
**Purpose**: Calculate the left child index of node at index `i`
- `(i)<<1`: Left shift by 1 bit (equivalent to multiplying by 2)
- `+1`: Add 1 to get left child
- **Formula**: Left child of node i = 2*i + 1
- **Example**: Left child of node 2 = 2*2 + 1 = 5

```c
#define RIGHT(i)   (((i)<<1)+2)
```
**Purpose**: Calculate the right child index of node at index `i`
- `(i)<<1`: Left shift by 1 bit (multiply by 2)
- `+2`: Add 2 to get right child
- **Formula**: Right child of node i = 2*i + 2
- **Example**: Right child of node 2 = 2*2 + 2 = 6

### Visual Tree Representation
```
Array indices:  [0] [1] [2] [3] [4] [5] [6]
Tree structure:
       0
      / \
     1   2
    / \ / \
   3 4 5   6

Parent-Child relationships:
- Node 0: Left=1, Right=2
- Node 1: Left=3, Right=4, Parent=0
- Node 2: Left=5, Right=6, Parent=0
```

### Data Structure Definition

```c
struct heap_s {
    int *v;
    int size;
};
```
**Line Analysis**:
- `struct heap_s {`: Begin structure definition named `heap_s`
- `int *v;`: Pointer to integer array that stores heap elements
- `int size;`: Current number of elements in the heap
- `};`: End structure definition

**Memory Layout Illustration**:
```
heap_s structure:
┌─────────────┬──────────┐
│    *v       │   size   │
│ (pointer)   │ (int: 4) │
└─────────────┴──────────┘
      │
      v
┌───┬───┬───┬───┬───┬───┐
│ 3 │ 7 │ 4 │ 10│ 15│ 8 │  <- Actual heap array
└───┴───┴───┴───┴───┴───┘
  0   1   2   3   4   5     <- Array indices
```

---

## Function Analysis

### swap() Function

```c
static void swap (heap_t *heap, int i ,int j) {
```
**Line Analysis**:
- `static`: Function has internal linkage (only visible within this file)
- `void`: Function returns nothing
- `swap`: Function name
- `heap_t *heap`: Pointer to heap structure
- `int i, int j`: Indices of elements to swap

```c
    int tmp;
```
**Purpose**: Declare temporary variable to hold one element during swap

```c
    tmp = heap->v[i];
```
**Purpose**: Store the value at index `i` in temporary variable
- `heap->v[i]`: Access element at index `i` in heap array

```c
    heap->v[i] = heap->v[j];
```
**Purpose**: Copy value from index `j` to index `i`

```c
    heap->v[j] = tmp;
```
**Purpose**: Copy temporary value (original `v[i]`) to index `j`

```c
    return;
```
**Purpose**: Exit function (optional for void functions)

```c
}
```
**Purpose**: End function definition

**Swap Visualization**:
```
Before swap(heap, 1, 4):
Array: [3, 7, 4, 10, 15, 8]
        ↑     ↑
        i=1   j=4

Step 1: tmp = heap->v[1] = 7
Step 2: heap->v[1] = heap->v[4] = 15
Step 3: heap->v[4] = tmp = 7

After swap:
Array: [3, 15, 4, 10, 7, 8]
```

### heapify() Function

```c
static void heapify (heap_t *heap, int i) {
```
**Purpose**: Maintain min-heap property starting from index `i`
- Assumes subtrees rooted at children are already heaps
- Moves element at `i` down until heap property is restored

```c
    int l, r, tmp;
```
**Purpose**: Declare local variables
- `l`: Will store left child index
- `r`: Will store right child index  
- `tmp`: Will store index of smallest element among parent and children

```c
    l = LEFT(i);
```
**Purpose**: Calculate left child index using macro
- Expands to: `l = (((i)<<1)+1);`

```c
    r = RIGHT(i);
```
**Purpose**: Calculate right child index using macro
- Expands to: `r = (((i)<<1)+2);`

```c
    if ((l<heap->size) && (heap->v[l]<heap->v[i]))
```
**Line Analysis**:
- `(l<heap->size)`: Check if left child exists (index within bounds)
- `&&`: Logical AND operator
- `(heap->v[l]<heap->v[i])`: Check if left child is smaller than parent
- **Overall**: "If left child exists AND is smaller than parent"

```c
        tmp = l;
```
**Purpose**: Set `tmp` to left child index (left child is currently smallest)

```c
    else
        tmp = i;
```
**Purpose**: Set `tmp` to parent index (parent is currently smallest)

```c
    if ((r<heap->size) && (heap->v[r]<heap->v[tmp]))
```
**Line Analysis**:
- `(r<heap->size)`: Check if right child exists
- `(heap->v[r]<heap->v[tmp])`: Check if right child is smaller than current smallest
- **Overall**: "If right child exists AND is smaller than current smallest"

```c
        tmp = r;
```
**Purpose**: Update `tmp` to right child index (right child is now smallest)

```c
    if (tmp != i) {
```
**Purpose**: Check if smallest element is not the parent
- If `tmp == i`, heap property is already satisfied
- If `tmp != i`, we need to swap and continue heapifying

```c
        swap (heap, i, tmp);
```
**Purpose**: Swap parent with smallest child

```c
        heapify (heap, tmp);
```
**Purpose**: Recursively heapify the affected subtree
- `tmp` now contains the original parent element
- Need to ensure it finds correct position in subtree

```c
    }
    return;
}
```
**Purpose**: End conditional block and function

**Heapify Visualization Example**:
```
Initial state (violates min-heap at index 0):
       10
      /  \
     3    4
    / \  /
   7  15 8

Step 1: Compare 10 with children 3 and 4
- Left child (3) < Parent (10) ✓
- Right child (4) < Left child (3) ✗
- Smallest = 3 (index 1)

Step 2: Swap 10 and 3
       3
      /  \
    10    4
    / \  /
   7  15 8

Step 3: Recursively heapify at index 1
- Compare 10 with children 7 and 15
- Left child (7) < Parent (10) ✓
- Smallest = 7 (index 3)

Step 4: Swap 10 and 7
       3
      /  \
     7    4
    / \  /
   10 15 8

Final result: Min-heap property restored
```

### build_heap() Function

```c
static void build_heap (heap_t *heap) {
```
**Purpose**: Convert an arbitrary array into a min-heap
- Uses bottom-up approach
- Only processes non-leaf nodes

```c
    int i;
```
**Purpose**: Declare loop variable

```c
    for (i=(heap->size>>1)-1; i>=0; i--) {
```
**Line Analysis**:
- `(heap->size>>1)`: Divide size by 2 (right shift)
- `-1`: Subtract 1 to get last non-leaf node index
- `i>=0`: Continue until we process the root
- `i--`: Process nodes from bottom to top

**Why start at `(size/2)-1`?**
- In a complete binary tree, nodes from index `size/2` to `size-1` are leaves
- Leaves already satisfy heap property (no children to violate it)
- We only need to heapify internal nodes

```c
        heapify (heap, i);
```
**Purpose**: Apply heapify to current node

```c
    }
    return;
}
```

**Build Heap Visualization**:
```
Original array: [10, 15, 20, 17, 8]
Size = 5, so start at index (5/2)-1 = 1

Tree representation:
       10
      /  \
     15   20
    / \
   17  8

Step 1: heapify(1) - Process node 15
- Children: 17, 8
- 8 < 15, so swap
       10
      /  \
     8    20
    / \
   17 15

Step 2: heapify(0) - Process root 10
- Children: 8, 20
- 8 < 10, so swap
       8
      /  \
     10   20
    / \
   17 15

- Recursively heapify(1):
  - Children of 10: 17, 15
  - 15 < 17, 15 < 10, so swap
       8
      /  \
     15   20
    / \
   17 10

Final min-heap: [8, 15, 20, 17, 10]
```

### heapSort() Function

```c
void heapSort (heap_t *heap) {
```
**Purpose**: Sort array using heap sort algorithm
- Note: Not `static` - this is the public interface
- Implements in-place sorting

```c
    int i, size;
```
**Purpose**: Declare variables
- `i`: Loop counter
- `size`: Store original heap size

```c
    build_heap (heap);
```
**Purpose**: Convert array to min-heap structure
- After this, smallest element is at index 0

```c
    size = heap->size;
```
**Purpose**: Save original size
- We'll modify `heap->size` during sorting
- Need to restore it at the end

**Main Sorting Loop**:
```c
    for (i=heap->size-1; i>=0; i--) {
```
**Purpose**: Extract elements from largest index down to 0
- Start from last position
- Work backwards to position 0

```c
        swap (heap, 0, i);
```
**Purpose**: Move smallest element (root) to position `i`
- Position `i` is the "sorted region"
- Root contains minimum element

```c
        heap->size--;
```
**Purpose**: Reduce heap size by 1
- Excludes the just-sorted element from heap
- Element at index `i` is now in final position

```c
        heapify (heap, 0);
```
**Purpose**: Restore heap property for remaining elements
- New root might violate heap property
- Only consider elements from 0 to `heap->size-1`

```c
    }
```

```c
    heap->size = size;
```
**Purpose**: Restore original size
- All elements are now sorted
- Heap structure contains sorted array

```c
    return;
}
```

**Heap Sort Complete Visualization**:
```
Initial array: [4, 10, 3, 5, 1]

Step 1: build_heap() creates min-heap
Result: [1, 4, 3, 5, 10]
       1
      / \
     4   3
    / \
   5  10

Step 2: Sorting iterations

Iteration 1 (i=4):
- swap(0,4): [10, 4, 3, 5, 1] - Move min(1) to end
- size becomes 4
- heapify(0): [3, 4, 10, 5 | 1] - Restore heap in first 4 elements
       3
      / \
     4  10
    /
   5

Iteration 2 (i=3):
- swap(0,3): [5, 4, 10, 3 | 1] - Move min(3) to position 3
- size becomes 3  
- heapify(0): [4, 5, 10 | 3, 1] - Restore heap in first 3 elements

Iteration 3 (i=2):
- swap(0,2): [10, 5, 4 | 3, 1] - Move min(4) to position 2
- size becomes 2
- heapify(0): [5, 10 | 4, 3, 1] - Restore heap in first 2 elements

Iteration 4 (i=1):
- swap(0,1): [10, 5 | 4, 3, 1] - Move min(5) to positio