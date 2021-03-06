class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        
        for center in range(2*len(s)-1):
            left = center // 2
            right = left + center % 2
            while left >= 0 and right < len(s) and s[left] == s[right]:
                res += 1
                left -= 1
                right += 1
                
        return res
    
if __name__ == '__main__':
    
    assert (Solution().countSubstrings("abc") == 3)

    assert (Solution().countSubstrings("aaa") == 6)
