# 🌀 Push Swap

A sorting algorithm implementation that uses **two stacks** to sort a list of integers using a variant of the **quick sort** algorithm. The goal is to sort the input list with the minimum number of operations using only a limited set of stack commands.

This project demonstrates **in-place sorting** (no additional data structures) using a constrained instruction set and algorithmic logic.

---

## ⚙️ Requirements

- `gcc` (or compatible C compiler)
- `make`

---

## 🚀 Usage

Clone the repository, build the program using `make`, and pass a list of integers as arguments:

```bash
make
./push_swap 3 2 1
```

This will output a list of operations that sort the input list.

---


## 🎮 Operations

| Command | Description                            |
|---------|----------------------------------------|
| `sa`    | Swap top two elements of stack A       |
| `sb`    | Swap top two elements of stack B       |
| `ss`    | `sa` and `sb` at the same time         |
| `pa`    | Push top of B onto A                   |
| `pb`    | Push top of A onto B                   |
| `ra`    | Rotate stack A up by 1                 |
| `rb`    | Rotate stack B up by 1                 |
| `rr`    | `ra` and `rb` at the same time         |
| `rra`   | Reverse rotate stack A down by 1       |
| `rrb`   | Reverse rotate stack B down by 1       |
| `rrr`   | `rra` and `rrb` at the same time       |

---

## 🛠 Testing

You can test the program with various input sizes and verify correctness and efficiency:

```bash
./push_swap 5 4 3 2 1
```

To count the number of operations:

```bash
./push_swap 5 4 3 2 1 | wc -l
```

To check if the output correctly sorts the input, use a checker (you may write one or use an existing one if available).

---

## ❗ Notes

- Input must contain **only integers** with no duplicates.
- Handles errors like invalid input or overflow.
- Larger inputs (e.g. 100 or 500 elements) will trigger more optimized sorting paths.

---
