# Day 4: Hashing Collisions & Tricks — Checklist

## Block 1: Architecture (2h)
- [ ] Read concepts.md. Understand why `O(1)` map lookup can fail.
- [ ] P1: Design HashMap. Implement bucketing using `vector<list<Node>>`. Use modulo operator for prime length size.
- [ ] Memorize the Anti-Hash trick structure (`splitmix64`).

## Block 2: Values to Ranges (Bucketing) (3h)
- [ ] Concept Check: Why a normal Hash Set fails for "difference of values <= t".
- [ ] P5: Contains Duplicate III — Write the mathematical bucket assignment formula: `(num + 1) / width - 1` for negative numbers.
- [ ] P6: Brick Wall — Understand why counting gaps is vastly more efficient than traversing every cell limit.

## Block 3: Fractions and Geometry (3h)
- [ ] Concept Check: Why does `double slope = (double)dy / dx` cause precision errors?
- [ ] P7: Fractional Recurring Decimal — Insert exactly at the string index logged in the map when the remainder repeats.
- [ ] P8: Max Points on a Line — Use `gcd(dx, dy)`. Make sure to standardize signs (e.g. `2/-3` becomes `-2/3`). Custom pair hash function required!

## Block 4: Math/Encryption Models (4h)
- [ ] P2: Encode Decode TinyURL — Just logic, but handle it using simple dual-mapping.
- [ ] P3: DNA Sequences — Read on mapping strings to numbers: `A=00, C=01, G=10, T=11`. Try bitshifting!
- [ ] P9: Number of Boomerangs — Basic distance formula squared to avoid doubles. Combine with `n*(n-1)` frequency counting calculation.

## Block 5: Consolidation (2h)
- [ ] Can you implement the Rabin Karp rolling hash base 26 formula? Write it down.
- [ ] Compile and verify Day 4.
