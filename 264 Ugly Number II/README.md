# Ugly Number II (Medium)

## Description

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

**Example:**

```html
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
```

**Note:**

- 1 is typically treated as an ugly number.
- n does not exceed 1690.

## Idea

**Approach 1:** One pass (Time Limit Exceeded)

Traverse each number and add the ugly number into the table until n-th has been found. For each number, search whether x/2 or x/3 or x/5 is in the table.

Time - O(n^2); Space - O(n)

**Approach 2:** Heap

For each ugly number x, add 2x, 3x and 5x into heap. Then remove x which is at the top of the heap. To avoid duplicated numbers, set structure can be applied instead of heap. (See solution_set and solution_pg)

n passes. For each pass, the insert operation is at O(lg(n)).

Time - O(n * lg(n)); Space - O(n)

**Approach 3:** Dynamic Programming using three pointers

dp[i] = min(dp[p_2] * 2, dp[p_3] * 3, dp[p_5] * 5)

This method save the time to keep the array sorted and the space to store three ugly numbers in advance (actually only one in advance).

Time - O(n); Space - O(n)
