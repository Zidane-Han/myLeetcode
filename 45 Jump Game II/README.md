# Jump Game II (Hard)

## Description

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

**Example:**

```html
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Note:**

You can assume that you can always reach the last index.

## Idea

- DP (time limited error)

  Traverse from pos 0 to n-1. For each pos, update the following nums[i] positions with the smallest steps.

- Greedy

  This solution maintains three variables:

  1. the maximum index reachable from `0` to `i`, denoted as `max_reachable`;
  2. the furthest we can reach within the current number of jumps, denoted as `furthest`. In other words, you can go `0` to `j` where `j <= furthest` in less than or equal to `jumps` steps.
  3. the number of jumps made so far, denoted as `jumps`.
  