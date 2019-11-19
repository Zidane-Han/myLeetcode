class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        # quicksort search

        def partition(nums, left, right):
            # from largest to smallest
            pivot = nums[left]
            low = left + 1
            fast = right

            while low <= fast:
                if nums[low] < pivot < nums[fast]:
                    nums[low], nums[fast] = nums[fast], nums[low]
                    low += 1
                    fast -= 1

                if nums[low] >= pivot:
                    low += 1
                if nums[fast] <= pivot:
                    fast -= 1

            nums[fast], nums[left] = nums[left], nums[fast]
            return fast

        left = 0
        right = len(nums) - 1

        while True:
            pos = partition(nums, left, right)
            if pos == k - 1:
                return nums[pos]
            elif pos < k - 1:
                left = pos + 1
            else:
                right = pos - 1


if __name__ == '__main__':
    nums = [3, 2, 1, 5, 6, 4]
    k = 2
    assert(Solution().findKthLargest(nums, k) == 5)

    nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k = 4
    assert(Solution().findKthLargest(nums, k) == 4)
