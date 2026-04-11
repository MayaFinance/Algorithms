# Day 3: In-Place Array Manipulation

## Focus: No Extra Space, No Output Array
Modify the input directly. Techniques: read/write pointer, sign-marking, cyclic placement, triple-reversal rotation, next permutation.

## In-Place Safety Rules
1. Never overwrite before reading (fast reads before slow writes)
2. Fill from back when merging into existing array
3. Sign-marking requires values in [1,n] (positive only)
4. Cyclic placement: track start of each cycle
5. Two-pass is still O(n) — first mark, then clean

## Files
| File | Purpose |
|---|---|
| `concepts.md` | Theory, 6 techniques, safety rules, pitfalls |
| `problems.md` | 10 problems |
| `solutions.cpp` | P1–P10 with dry runs, Python |
| `todo.md` | Checklist |
| `index.html` | Dashboard |
