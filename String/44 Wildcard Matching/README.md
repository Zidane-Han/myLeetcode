# Wildcard Matching (Hard)

## Description

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

```html
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
```

The matching should cover the entire input string (not partial).

Note:

- s could be empty and contains only lowercase letters a-z.
- p could be empty and contains only lowercase letters a-z, and characters like ? or *.

**Example 1:**

```html
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```html
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
```

**Example 3:**

```html
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

**Example 4:**

```html
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
```

**Example 5:**

```html
Input:
s = "acdcb"
p = "a*c?b"
Output: false
```

## Idea

1. DP.

- The element dp[i][j] of the matrix indicates the matching result of the first i-th elements of string s and the first j-th elements of pattern p.
- The time and space complexity are both O(m*n).

2. One pass.

- One pointer for each to pass through each letter. One pointer for string s to indicate the last position that match with "\*"; one pointer for pattern p to indicate the last "*" position.
- time complexity O(n); space O(n)
