import heapq

class Solution:
    def findKthLargest(self, arr, k):

        if k > len(arr) or not arr or k < 0:
            return

        heapq.heapify(arr)
        for i in range(len(arr) - k + 1):
            pop = heapq.heappop(arr)

        return pop


if __name__ == '__main__':
    nums = [3, 2, 1, 5, 6, 4]
    k = 2
    assert(Solution().findKthLargest(nums, k) == 5)

    nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k = 4
    assert(Solution().findKthLargest(nums, k) == 4)
