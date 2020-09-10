# Super Ugly Number (Medium)

## Description

Write a program to find the n-th super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

**Example:**

```html
Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
```

**Note:**

- 1 is a super ugly number for any given primes.
- The given numbers in primes are in ascending order.
- 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
- The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

## Idea

Similar to **Prob 264 Ugly Number II**.

**Approach 1:** Heap

If use the set data structure (in cpp), the programme will cause runtime error.

The priority_queue data structure will be fine, slightly faster than set.

**Approach 2:** Dynamic Programming

It is not reasonable to create multiple pointers as long as the number of the primes. Instead, we could create a vector to store the positions of the pointers.
