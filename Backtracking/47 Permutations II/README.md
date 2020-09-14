# Permutations II (Medium)

## Description

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

**Example:**

```html
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

## Idea

Variation of Prob 46.

The only difference is to skip the duplicated numbers. [1,1,2] is to skip the duplicate number; [1,2,1] is not to skip.

Line 11 -- "if (i > 0 && nums[i]==nums[i-1] && !visited[i-1])   continue;".
