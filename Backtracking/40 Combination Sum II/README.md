# Combination Sum II (Medium)

## Description

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

**Note**:

- All numbers (including target) will be positive integers.
- The solution set must not contain duplicate combinations.

**Example 1:**

```html
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

**Example 2:**

```html
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
```

## Idea

Similar to Prob 39. The only difference is to skip duplicated number when traverse the candidates.
