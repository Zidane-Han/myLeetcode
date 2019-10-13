class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """

        dict = {}
        for char in s:
            if char in dict:
                dict[char] += 1
            else:
                dict[char] = 1

        res = 0
        for num in dict.values():
            res += num % 2

        if res <= 1:
            return True
        else:
            return False


if __name__ == '__main__':

    s = "code"
    assert(Solution().canPermutePalindrome(s) == False)

    s = "aab"
    assert(Solution().canPermutePalindrome(s) == True)