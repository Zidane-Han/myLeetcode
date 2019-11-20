# Shortest Subarray with Sum at Least K (Hard)

## Description
Return the **length** of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

**Examples 1:**
```html
Input: A = [1], K = 1

Output: 1
```

**Examples 2:**
```html
Input: A = [1,2], K = 4

Output: -1
```

**Examples 3:**
```html
Input: A = [2,-1,2], K = 3

Output: 3
```

**Note:**
1. 1 <= A.length <= 50000
2. -10^5 <= A[i] <= 10^5
2. 1 <= K <= 10^9

## Idea
Method 1: two pointers (Time Limit Exceeded)

Method 2: Stack

We can rephrase this as a problem about the prefix sums of A. Let P[i] = A[0] + A[1] + ... + A[i-1]. We want the smallest y-x such that y > x and P[y] - P[x] >= K.

Motivated by that equation, let opt(y) be the largest x such that P[x] <= P[y] - K. We need two key observations:
- If x1 < x2 and P[x2] <= P[x1], then opt(y) can never be x1, as if P[x1] <= P[y] - K, then P[x2] <= P[x1] <= P[y] - K but y - x2 is smaller. This implies that our candidates x for opt(y) will have increasing values of P[x].
- If opt(y1) = x, then we do not need to consider this x again. For if we find some y2 > y1 with opt(y2) = x, then it represents an answer of y2 - x which is worse (larger) than y1 - x.

Algorithm:
1. Maintain a "monoqueue" of indices of P: a deque of indices x_0, x_1, ... such that P[x_0], P[x_1], ... is increasing.
2. When adding a new index y, we'll pop x_i from the end of the deque so that P[x_0], P[x_1], ..., P[y] will be increasing.
3. If P[y] >= P[x_0] + K, then (as previously described), we don't need to consider this x_0 again, and we can pop it from the front of the deque.