# Push Swap

![42 School](https://img.shields.io/badge/42%20School-Project-blue)

A highly efficient sorting algorithm using two stacks with a limited set of operations. This project was completed as part of the 42 curriculum.

## Overview

The Push Swap project challenges you to sort a set of random integers using two stacks with a minimal number of operations. The algorithm must be optimized to use as few actions as possible, making this an exercise in algorithm efficiency.

## Features

- Sorts integers using only two stacks and a restricted set of operations
- Implements different algorithms based on input size for optimal performance
- Handles various edge cases (duplicates, non-numeric input, etc.)
- Optimized for minimum number of operations

## How It Works

The algorithm uses two stacks:
- Stack A: Initially contains all input numbers in arbitrary order
- Stack B: Initially empty

The goal is to sort all numbers in ascending order on Stack A using only the allowed operations.

## Allowed Operations

| Command | Name | Description |
| ------- | ---- | ----------- |
| `sa` | Swap A | Swaps the first two elements at the top of Stack A |
| `sb` | Swap B | Swaps the first two elements at the top of Stack B |
| `ss` | Swap Both | Executes `sa` and `sb` simultaneously |
| `pa` | Push to A | Takes the first element from Stack B and puts it at the top of Stack A |
| `pb` | Push to B | Takes the first element from Stack A and puts it at the top of Stack B |
| `ra` | Rotate A | Shifts up all elements of Stack A by 1 (first element becomes last) |
| `rb` | Rotate B | Shifts up all elements of Stack B by 1 (first element becomes last) |
| `rr` | Rotate Both | Executes `ra` and `rb` simultaneously |
| `rra` | Reverse Rotate A | Shifts down all elements of Stack A by 1 (last element becomes first) |
| `rrb` | Reverse Rotate B | Shifts down all elements of Stack B by 1 (last element becomes first) |
| `rrr` | Reverse Rotate Both | Executes `rra` and `rrb` simultaneously |

## Installation

Clone the repository and its submodules:

```bash
git clone --recursive https://github.com/yourusername/push_swap.git
cd push_swap
```

Build the program:

```bash
make
```

## Usage

To run the program, use the following command:

```bash
./push_swap [numbers]
```

Example:

```bash
./push_swap 5 2 9 1 4
```

This will output the sequence of operations needed to sort the given numbers.

## Algorithm Strategy

The program implements different sorting strategies based on input size:

- For ≤ 3 elements: Direct sorting with specific move patterns
- For 4-5 elements: Small set optimization algorithm
- For larger sets: Chunking strategy with optimized moves
