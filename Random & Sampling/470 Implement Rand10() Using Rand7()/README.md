# Implement Rand10() Using Rand7() (Medium)

## Description
Given a function *rand7* which generates a uniform random integer in the range 1 to 7, write a function *rand10* which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().


**Example 1:**
```python
Input: 1
Output: [7]
```

**Example 2:**
```python
Input: 2
Output: [8,4]
```

## Idea
Sample Rand7() \* Rand7(), which should be in range [1, 49]. 

if the result is range [1, 40], return remainder; otherwise, keep sampling