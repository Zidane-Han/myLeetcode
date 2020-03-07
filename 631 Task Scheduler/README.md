# Task Scheduler (Medium)

## Description
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval **n** that means between two **same tasks**, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the **least** number of intervals the CPU will take to finish all the given tasks.

**Example:**
```html
Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
```

**Note:**
- The number of tasks is in the range [1, 10000].
- The integer n is in the range [0, 100].

## Idea
1. find the most frequent element(s)
2. assign the element every (n+1) position. e.g. AXXAXXA
3. if there are more than one elements with the highest frequency, try them as whole. e.g. ABXXABXXAB
