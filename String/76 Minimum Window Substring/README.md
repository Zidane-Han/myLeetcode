# Minimum Window Substring (Hard)

## Description

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

**Example:**

```html
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
```

**Note:**

- If there is no such window in S that covers all characters in T, return the empty string "".
- If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

## Idea

Sliding window (as hint)

Use two pointers: the right pointer firstly to expand and the left pointer then to contract.

Basic method: s_freq hashtable for string s and t_freq hashtable for string t. When the right pointer matches the char in t, s_freq[char] + 1; when the left pointer matches, s_freq[char]-1. Once all the characters meet the condition that s_freq[char] >= t_freq[char], the length and result could be updated.

Improved method: s_freq and t_freq can be replaced by only one hashtable *freq*, so the space and the time for comparison could be saved. The frequencies of characters appeared in t are first put into hashtable freq. Correspondingly, when the right pointing to s meets the char, -1; when the left meets the char, +1.

