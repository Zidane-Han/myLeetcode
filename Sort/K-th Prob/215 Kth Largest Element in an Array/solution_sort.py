class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort(key = lambda x: -x)
        return nums[k-1]


if __name__ == '__main__':
    nums = [3, 2, 1, 5, 6, 4]
    k = 2
    assert(Solution().findKthLargest(nums, k) == 5)

    nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k = 4
    assert(Solution().findKthLargest(nums, k) == 4)
