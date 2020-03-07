class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        length = len(s)
        wordDict = set(wordDict)

        # 0 for no; 1 for yes
        dp = [0] * (length + 1)
        dp[0] = 1

        for i in range(length + 1):
            for j in range(i):
                if (dp[j] and s[j:i] in wordDict):
                    dp[i] = 1
                    break

        return dp[-1] == 1


if __name__ == '__main__':
    s = "leetcode"
    wordDict = ["leet", "code"]
    assert (Solution().wordBreak(s, wordDict) == True)

    s = "applepenapple"
    wordDict = ["apple", "pen"]
    assert (Solution().wordBreak(s, wordDict) == True)

    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    assert (Solution().wordBreak(s, wordDict) == False)