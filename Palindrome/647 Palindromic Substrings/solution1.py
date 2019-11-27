class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        def isPalindromic(string):
            if string == string[::-1]:
                return True
            else:
                return False
            
        res = 0
        for i in range(len(s)+1):
            for j in range(i+1, len(s)+1):
                if isPalindromic(s[i:j]):
                    res += 1
                    
        return res

    
if __name__ == '__main__':
    
    assert (Solution().countSubstrings("abc") == 3)

    assert (Solution().countSubstrings("aaa") == 6)
