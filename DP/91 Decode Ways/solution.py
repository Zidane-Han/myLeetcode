class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == "": return 0
        solution = [0] * (len(s) + 1)
        solution[0] = 1

        for i in range(1, len(s) + 1):
            if s[i - 1] != "0":
                solution[i] = solution[i - 1]

            if i != 1 and s[i - 2:i] < "27" and s[i - 2:i] > "09":
                solution[i] += solution[i - 2]

        return solution[len(s)]


if __name__ == '__main__':
    s = "12"
    assert (Solution().numDecodings(s) == 2)
    s = "226"
    assert (Solution().numDecodings(s) == 3)