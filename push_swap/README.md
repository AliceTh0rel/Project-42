
# push_swap

This project is an algorithmic challenge from 42 school.  
It sorts a stack of integers using a limited set of stack operations, aiming to use the least possible number of moves.

## Objectives

- Implement efficient sorting algorithms for small and large data sets.
- Work with stacks and linked lists in C.
- Optimize the number of operations.
- Handle input errors and invalid data.

## Allowed operations

- `sa` / `sb` / `ss` – swap the first 2 elements of stack a, b, or both.
- `pa` / `pb` – push the top element from one stack to another.
- `ra` / `rb` / `rr` – rotate stack a, b, or both (first element becomes last).
- `rra` / `rrb` / `rrr` – reverse rotate stack a, b, or both (last element becomes first).

## Usage

```bash
# Compile
make

# Run push_swap with arguments
./push_swap 2 1 3 6 5 8


# Algorithm explanation

For small stacks (≤ 5 elements), the program uses hardcoded optimized patterns:

    3 elements: minimal swaps/rotations to sort directly.

    5 elements: extract the two smallest numbers to stack B, sort the remaining 3 in stack A, then push back.

For larger stacks, a modified Turkish algorithm is used:

    Indexing: Each number is given an index based on its sorted position.

    Cost calculation: For every element in stack B, the algorithm calculates the number of moves required to place it in its correct position in stack A. This includes both rotations and reverse rotations.

    Choosing the best move: The element with the lowest cost is chosen. The stacks are rotated in the most efficient direction (sometimes simultaneously with rr/rrr).

    Push and repeat: Push the chosen element to stack A and repeat until stack B is empty.

    Final rotation: Rotate stack A so that the smallest element is at the top.

This approach minimizes the total number of operations, especially for large datasets, and adapts better than the pure Turkish method when facing uneven distributions or near-sorted data.
