# Day 2: Two Pointers (Opposite Direction)

## Overview
Inward two pointers eliminate O(n²) pair-scanning by exploiting sorted order monotonicity. One pointer at each end, moving inward under clear logical rules.

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Theory: when to use, decision guide, patterns (2sum,3sum,palindrome,container), mistakes |
| `problems.md` | 12 problems: two-sum to trapping rain water |
| `solutions.cpp` | Full solutions with dry runs + Python |
| `todo.md` | 14h study checklist |
| `index.html` | Interactive dashboard |

## Key Rule
> `sum < target → l++` (need bigger left). `sum > target → r--` (need smaller right). Container → move shorter height. Palindrome → mismatch means try skipping one side.
