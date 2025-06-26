# 📚 Quick Sort for Two Stacks

This program takes a list of integers and sorts it using **two stacks** with a Quick Sort algorithm adapted for stack operations only.

---

# ⚙️ Features

- In-place sorting using only two stacks.
- Recursive Quick Sort based on median partitioning.
- Sorting done entirely with stack operations (push, swap, rotate).
- No extra data structures beyond the two stacks.

---

# 🎮 Behavior

- The input list is loaded into stack A.
- The algorithm finds the median value in the current stack segment.
- Elements are pushed between stack A and stack B to partition around the median.
- Recursive sorting is performed on the partitions within the two stacks.
- Sorted elements are combined back into stack A.

---

# 🚀 Usage

# 🚀 Usage

### 🔧 Build

```bash
make

▶️ Run

./push_swap [list of integers]

Example:

./push_swap 3 2 1 6 5

The program will output a sequence of stack operations to sort the given list.

---

# ⚙️ Operations Table

| Operation | Description                               |
|-----------|-------------------------------------------|
| `sa`      | Swap the first two elements of stack A     |
| `sb`      | Swap the first two elements of stack B     |
| `ss`      | Perform `sa` and `sb` simultaneously       |
| `pa`      | Push the top element from stack B to stack A |
| `pb`      | Push the top element from stack A to stack B |
| `ra`      | Rotate stack A (shift up all elements)      |
| `rb`      | Rotate stack B (shift up all elements)      |
| `rr`      | Perform `ra` and `rb` simultaneously         |
| `rra`     | Reverse rotate stack A (shift down all elements) |
| `rrb`     | Reverse rotate stack B (shift down all elements) |
| `rrr`     | Perform `rra` and `rrb` simultaneously       |

---

# 🛠 Algorithm

This implementation uses a Quick Sort approach adapted for two stacks:

- The input list is initially placed in stack A.
- The median of the current segment is found to partition elements.
- Elements smaller or equal to the median are pushed to stack B; others stay or are rotated in stack A.
- Recursion sorts partitions in both stacks by applying the same process.
- Finally, all elements are merged back into stack A, resulting in a sorted sequence.

Because sorting is done by rearranging elements within the two stacks using only stack operations, this is considered an **in-place sorting algorithm**.
