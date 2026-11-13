# push_swap

Sorts a stack of integers using the fewest possible moves, with only two stacks (`a` and `b`) and a fixed set of operations.

```
make
./push_swap 3 2 5 1 4     # prints the list of moves that sorts the numbers
```

**Operations:** `sa`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

**Approach:** push elements from `a` to `b` one at a time, always choosing the one that is cheapest to move. When three are left in `a`, sort them directly, then push everything back from `b` in order and rotate `a` so the minimum is on top. Stacks of 2 and 3 are handled with dedicated cases.

It prints `Error` if the input has non-integers, duplicates or values outside the `int` range.
