class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        stack = []
        res = [0] * len(T)

        for i in range(len(T) - 1, -1, -1):
            while stack and T[i] >= T[stack[-1]]:
                stack.pop()
            if stack:
                res[i] = stack[-1] - i
            stack.append(i)

        return res


if __name__ == '__main__':

    T = [73, 74, 75, 71, 69, 72, 76, 73]
    assert(Solution().dailyTemperatures(T) == [1, 1, 4, 2, 1, 1, 0, 0])