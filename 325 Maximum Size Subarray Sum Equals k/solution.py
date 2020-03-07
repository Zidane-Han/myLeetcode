class Solution:
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ## hash table
        summ = 0
        count = 0
        dic = {}
        dic[0] = -1
        for i, num in enumerate(nums):
            summ += num
            if summ not in dic:
                dic[summ] = i
            
            if summ-k in dic:
                count = max(count, i-dic[summ-k])
        return count


if __name__ == '__main__':

    nums = [1, -1, 5, -2, 3]
    k = 3
    assert(Solution().maxSubArrayLen() == 4)

    nums = [-2, -1, 2, 1]
    k = 1
    assert(Solution().maxSubArrayLen() == 2)
