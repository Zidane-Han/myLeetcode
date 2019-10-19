class Solution(object):
    def Games24(self, p):
        # p: [list]
        if len(p) == 2:
            eps = 10e-10
            x = p[0]
            y = p[1]
            if min([abs(x + y - 24), abs(x - y - 24), abs(y - x - 24), abs(x * y - 24)]) < eps:
                return True
            elif x != 0 and abs(y / x - 24) < eps:
                return True
            elif y != 0 and abs(x / y - 24) < eps:
                return True
            else:
                return False


        for i in range(len(p) - 1):
            for j in range(i + 1, len(p)):
                pp = p.copy()
                x = p[i]
                y = p[j]
                pp.remove(x)
                pp.remove(y)
                if self.Games24(pp + [x + y]):
                    return True
                elif self.Games24(pp + [x - y]):
                    return True
                elif self.Games24(pp + [y - x]):
                    return True
                elif self.Games24(pp + [x * y]):
                    return True
                elif x != 0 and self.Games24(pp + [y / x]):
                    return True
                elif y != 0 and self.Games24(pp + [x / y]):
                    return True

    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        res = self.Games24(nums)
        if res:
            return True
        else:
            return False


if __name__ == '__main__':
    nums = [4, 1, 8, 7]
    assert (Solution().judgePoint24(nums) == True)
    nums = [1, 2, 1, 2]
    assert (Solution().judgePoint24(nums) == False)