class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        res = ""
        for char in num:
            while k and res and res[-1] > char:
                res = res[:-1]
                k -= 1

            res += char

        res = res[:len(res) - k]

        # delete leading zero
        while res and res[0] == '0':
            res = res[1:]

        if not res:
            return "0"
        else:
            return res


if __name__ == '__main__':

    num = "1432219"
    k = 3
    assert(Solution().removeKdigits(num, k) == "1219")

    num = "10200"
    k = 1
    assert(Solution().removeKdigits(num, k) == "200")

    num = "10"
    k = 2
    assert(Solution().removeKdigits(num, k) == "0")