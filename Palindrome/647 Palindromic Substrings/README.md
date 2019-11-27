# Palindromic Substrings (Medium)

## Description
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

**Example 1:**
```html
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
``` 

**Example 2:**
```html
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

**Note:** The input string length won't exceed 1000.

## Idea
This is a very good problem that can be solved with different approaches.

Approach 1: brute force
- Time complexity O(n^3) and O(n^2) check

Approach 2: find the palindromic around the center
- Time complexity O(n^2) and O(1) space

Approach 3: dynamic programming
- dp[i-1][j+1] is palindromic when dp[i][j] is palindromic and s[i-1] == s[j+1]
- Time complexity O(n^2) and O(n^2) space

Approach 4: Manacher Algorithm
- Time complexity O(n)
