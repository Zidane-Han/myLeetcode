class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # res: store currt content
        # resStack: the previous res
        # numStack: the previous value
        # res = resStack + numStack * res

        resStack = []
        numStack = []
        res = ""

        i = 0
        tmpNum = 0
        while (i < len(s)):
            ch = s[i]
            if ch.isdigit():
                while s[i].isdigit():
                    tmpNum = 10 * tmpNum + int(s[i])
                    i += 1
            elif ch == "[":
                resStack.append(res)
                res = ""
                numStack.append(tmpNum)
                tmpNum = 0
                i += 1
            elif ch == "]":
                res = resStack.pop() + numStack.pop() * res
                i += 1
            else:
                res += ch
                i += 1

        return res


if __name__ == '__main__':

    s = "3[a]2[bc]"
    assert(Solution().decodeString(s) == "aaabcbc")

    s = "3[a2[c]]"
    assert(Solution().decodeString(s) == "accaccacc")

    s = "2[abc]3[cd]ef"
    assert(Solution().decodeString(s) == "abcabccdcdcdef")