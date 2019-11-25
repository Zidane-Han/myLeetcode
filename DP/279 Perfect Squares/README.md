# Perfect Squares (Medium)

## Description
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

**Example 1:**
```html
Input: n = 12

Output: 3 

Explanation: 12 = 4 + 4 + 4.
```
**Example 2:**
```html
Input: n = 13

Output: 2

Explanation: 13 = 4 + 9.
```

## Idea
**Approach 1:** Recursion (Time Limit Exceeded)

The number n can always be expressed as *n = a \* x^2 + b*. Traverse all the possible x, then apply the same function for b until b reaches 0.

Time - O(n^2); Space - O(n)

**Approach 2:** DP

Assume dp[i] is known, then dp[i+j\*j] will be min(dp[i+j\*j], dp[i]+1).

Time - O(n^2); Space - O(n)

**Approach 3:**

Four-square theorem: every natural number can be represented as the sum of four integer squares. (https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem)

Time - O(n); Space - O(n)
