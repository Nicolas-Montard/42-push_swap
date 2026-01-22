*This project has been created as part of the 42 curriculum by nmontard, aslimani.*

# Push_swap 

## Description 

The **push_swap** project consists of sorting a list of integers using two stacks (`a` and `b`) and a limited set of allowed operations.

The objective is to output the **smallest possible sequence of operations** that sorts stack `a` in ascending order. This project focuses on algorithmic complexity, optimization, and adapting classical sorting algorithms to strict constraints. 

--- 

## Project Overview 

- Sorting using two stacks and predefined operations
- Multiple sorting strategies with different complexity classes 
- Runtime strategy selection 
- Error handling and input validation 
- Benchmark mode 
--- 

## Instructions 

### Compilation 
---

```bash
Execution

./push_swap [options] <numbers>
```

Available options
- --simple : Force the O(n²) strategy
- --medium : Force the O(n√n) strategy
- --complex : Force the O(n log n) strategy
- --adaptive : Automatic strategy selection (default)
- --bench : Display benchmark information (stderr)

### Usage Examples
---
```bash
- ./push_swap 2 1 3 6 5 8
```
```bash
- ./push_swap --simple 5 4 3 2 1
``` 
```bash
- ./push_swap --medium 4 67 3 87 23
``` 
```bash
- ./push_swap --adaptive --bench 4 67 3 87 23
```
---

### Algorithms

---

#### Disorder Metric

---

Before applying any sorting strategy, the program computes a disorder metric representing how far the initial stack is from being sorted.
The disorder is a value between 0 and 1:
- 0 means the stack is already sorted
- 1 means the stack is in the worst possible order
It is calculated by counting the number of inverted pairs compared to the total number of possible pairs.
This metric is used to help select the most appropriate strategy.

---

#### Simple Strategy - Selection Sort (O(n²))

---

The simple strategy is based on a selection sort adaptation designed to work within the constraints of the Push_swap project. 
The algorithm repeatedly searches for the smallest value in stack `a`, rotates the stack until this value reaches the top, and then pushes it to stack `b`. This process is repeated until stack `a` becomes empty. Once all elements have been moved to stack `b`, they are pushed back to stack `a`, resulting in a fully sorted stack in ascending order.

This strategy was chosen because it is straightforward to implement and easy to reason about. Each operation has a clear purpose, which makes the algorithm reliable and simple to debug. However, because the minimum search and rotations are performed for every element, the number of generated operations grows quickly as the input size increases.

In the Push_swap operation model, this strategy has a time complexity of **O(n²)** and is mainly used as a baseline to compare more efficient algorithms.

---

#### Medium Strategy - Chunk Sort (O(n√n))

---

The medium strategy relies on a chunk-based sorting approach to significantly reduce the number of operations compared to quadratic algorithms. 
The idea is to divide the input range into several chunks, usually proportional to the square root of the input size. Elements belonging to the current chunk are progressively pushed from stack `a` to stack `b`, while rotations are used to reach them efficiently.

During this process, stack `b` is partially organized in order to simplify the reinsertion phase. Once all chunks have been processed, the elements stored in stack `b` are pushed back to stack `a` in the correct order, producing a sorted stack.

This strategy offers a good compromise between performance and implementation complexity. It scales much better than selection sort for medium-sized inputs while remaining understandable and predictable. In the Push_swap operation model, its time complexity is **O(n√n)**, making it well suited for this complexity range. 

---

#### Complex Strategy - Quick Sort (O(n log n))

---

The complex strategy is based on a recursive quick sort adaptation with stack partitioning.

The algorithm works by recursively dividing the data into smaller virtual sub-stacks and sorting them independently. It begins with an initial split: a pivot is selected using the median-of-three method (comparing the first, middle, and last elements of the current range), and all values smaller than or equal to the pivot are pushed from stack `a` to stack `b`, while values greater than the pivot remain in stack `a`.

These two groups are then treated as virtual sub-stacks, tracked by passing their calculated sizes as parameters to the recursive functions. The algorithm then calls sort_a followed by sort_b, which are the core recursive functions. Each function splits its own sub-stack using a new pivot and recursively calls sort_a and then sort_b again, creating a tree-like structure of function calls.

The order of these calls is essential: by always processing stack `a` before stack `b`, the algorithm ensures that larger elements are handled first and smaller elements last. This guarantees that the largest values settle at the bottom of the stack while the smallest values end up at the top, maintaining proper ordering throughout the process.

Each recursive call has a base case: when a sub-stack size falls below 16 elements, a selection sort adapted to work within the constraints of the sub-stack is applied. This adapted selection sort uses rotations to isolate and sort the targeted portion of the stack efficiently.

The recursion continues until all sub-stacks have been reduced to sizes smaller than 16 and sorted. Once all recursive calls complete, the entire stack is sorted in ascending order.
This strategy was chosen because quick sort is highly efficient for large datasets and adapts well to the two-stack constraint. The median-of-three pivot selection helps avoid worst-case scenarios, and the hybrid approach (quick sort + selection sort for small ranges) optimizes performance.

In the Push_swap operation model, this strategy achieves a time complexity of **O(n log n)**: at each recursion level, the algorithm performs O(n) Push_swap operations (rotations and pushes) to split the sub-stack, and the median-of-three pivot selection typically creates a recursion tree of logarithmic depth O(log n). The space complexity is **O(log n)** due to the recursive call stack depth in the average case. The threshold of 16 elements for switching to selection sort prevents worst-case recursion depth and ensures reliable performance. This makes it the most efficient algorithm implemented in this project for large dataset.

#### Error Handling

The program prints Error\n to standard error in the following cases:
- Non-numeric arguments
- Duplicate values
- Integer overflow
- Invalid input format


## Resources

https://en.wikipedia.org/wiki/Big_O_notation

https://loud-technology.com/blog/notation-grand-o-performance-complexite-algorithmique/

https://info.blaisepascal.fr/nsi-complexite-dun-algorithme/

https://www.geeksforgeeks.org/c/c-program-for-selection-sort/

https://element84.com/software-engineering/chunks-and-chunkability-tyranny-of-the-chunk/

https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/

https://en.wikipedia.org/wiki/Quicksort
