class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        
        dp = [[False] * length for i in range(length)]
        
        res = 0
        for i in range(length-1, -1, -1):
            for j in range(i, length):
                dp[i][j] = (s[i] == s[j]) and (j-i <= 2 or dp[i+1][j-1])
                if dp[i][j]:
                    res += 1
                    
        return res
    
if __name__ == '__main__':
    
    assert (Solution().countSubstrings("abc") == 3)

    assert (Solution().countSubstrings("aaa") == 6)
