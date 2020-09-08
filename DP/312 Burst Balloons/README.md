# Burst Balloons (Hard)

## Description

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

**Note:**

- You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
- 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

**Example:**

```html
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
```

## Idea

Variation of Matrix-Chain problem.

Define dp[i, j] as the maximum coins can get with interval [i, j].

If the next burst balloons is k-th (i<k<j), then suppose dp[i, k-1] and dp[k+1, j] have been know. So the top problem can be solved from the solutions of the subproblems. 

**Transition function:** dp[i, j] = max(dp[i, j], dp[i, k-1]+dp[k+1, j]+nums[i-1]\*nums[k]\*nums[j+1])

Tricks: 1) append 1 at the front and back of the array. 2) traverse the interval [i, j] from smaller to larger, so that the larger interval solutions can be retrieved from smaller interval ones.

