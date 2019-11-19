class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        dp = {}
        wordDict = set(wordDict)
        return self.helper(s, wordDict, dp)

    def helper(self, s, wordDict, dp):
        if s in dp:
            return dp[s]

        if not s:
            return [""]

        res = []
        for i in range(len(s) + 1):
            if s[:i] in wordDict:
                s_remainder = self.helper(s[i:], wordDict, dp)
                for item in s_remainder:
                    res.append(s[:i] + (" " if item else "") + item)
        dp[s] = res

        return res


if __name__ == '__main__':
    s = "catsanddog"
    wordDict = ["cat", "cats", "and", "sand", "dog"]
    print(Solution().wordBreak(s, wordDict))
    print("result =", ["cats and dog", "cat sand dog"])

    s = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    print(Solution().wordBreak(s, wordDict))
    print("result =", ["pine apple pen apple", "pineapple pen apple", "pine applepen apple"])

    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    print(Solution().wordBreak(s, wordDict))
    print("result =", [])
