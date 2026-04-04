# Difference Array Practice Challenges

This document outlines standard and advanced problems demonstrating the power of the Difference Array pattern.

## Problem 1: Range Addition (LeetCode 370)
**Description:** 
Given an integer `n` outlining an array composed strictly of `0`s spanning from index `0` to `n-1`, and a list of updates `[startIndex, endIndex, inc]`, return the final state of the sequence after applying all updates.

**Goal:**
Observe overlapping addition layers interacting and cancelling predictably, resolving via a single sequential prefix-sum resolution at the end.

## Problem 2: Corporate Flight Bookings (LeetCode 1109)
**Description:**
You are given `n` flights labeled from 1 to `n`. You are given a list of flight bookings where `bookings[i] = [first_i, last_i, seats_i]` indicating a booking for `seats_i` reserved for each flight in the inclusive range `[first_i, last_i]`.
Return an array of integers representing the number of seats booked on each flight.

**Goal:**
Carefully handle **1-based indexing** from problem domain coordinates translated into a **0-based indexing** implementation domain via buffer-sizing alignments.

## Problem 3: Little Girl and Maximum Sum (Codeforces 276C)
**Description:**
You are given an array of size `N`. You have `Q` range queries. Before answering the queries, you are allowed to mathematically arrange the elements of the original array in any order you choose. Find an arrangement of the initial array elements that ultimately maximizes the sum of all range queries applied.

**Goal:**
Extrapolate the Difference Array to be a tool for **frequency mapping**.
- Use the given `Q` ranges to simulate updating a `freq_diff` by `+1`.
- Prefix sum this difference array to find out which indexes get queried the most.
- Pair the highest values in the sorted initial array with the most queried indexes locally using a Greedy dot-product pattern.

## Problem 10: Car Pooling (LeetCode 1094)
**Description:**
There is a car with `capacity` empty seats. The vehicle only drives east. You are given an integer `capacity` and an array `trips` where `trips[i] = [numPassengers_i, from_i, to_i]` indicates that the `i`th trip has `numPassengers_i` passengers and the locations to pick them up and drop them off are `from_i` and `to_i` respectively. Return `true` if it is possible to pick up and drop off all passengers for all the given trips, or `false` otherwise.

**Goal:**
Standard 1D difference array simulation to track maximum capacity usage over time.

## Problem 11: My Calendar II (LeetCode 731)
**Description:**
Implement a `MyCalendarTwo` class to store your events. A new event can be added if adding the event will not cause a triple booking (three events intersect).

**Goal:**
Use a TreeMap (`std::map` in C++) as a Difference Array to handle implicitly large coordinate spaces and dynamically track overlapping intervals without a predefined static array size.

## Problem 12: Describe the Painting (LeetCode 1943)
**Description:**
There is a long and thin painting that can be represented by a number line. You are given a 2D integer array `segments`, where `segments[i] = [start_i, end_i, color_i]` represents a half-closed segment `[start_i, end_i)` painted with color `color_i`. Return the 2D array representing the painting.

**Goal:**
Sweep-line / Difference Array with mapping. Understanding how to handle interval ends and overlapping boundaries correctly when merging properties (colors) directly on a number line.

## Problem 13: Stamping the Grid (LeetCode 2132)
**Description:**
You are given an `m x n` binary matrix `grid` where `0` represents an empty cell and `1` represents an occupied cell. You are also given integers `stampHeight` and `stampWidth`. You want to explicitly cover all empty cells in the grid with stamps such that no stamp covers any occupied cell and stamps can overlap.

**Goal:**
Mastering 2D Difference Arrays AND 2D Prefix Sums simultaneously. Use 2D Prefix sums to validate if a stamp can be placed cleanly, then use a 2D Difference Array to apply the stamp across regions to ensure all empty cells are hit.

## Problem 14: Rectangle Area II (LeetCode 850)
**Description:**
You are given a 2D array of axis-aligned rectangles. Return the total area covered by all rectangles in the plane. Since the answer may be too large, return it modulo `10^9 + 7`.

**Goal:**
The Ultimate Boss. Combining Coordinate Compression, Sweep-Line algorithms (which is the continuous application of a difference array mapped against an event timeline), and Active Interval processing to calculate geometric unions in massive 2D constraints.
