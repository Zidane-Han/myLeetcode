class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        red = 0
        white = 0
        blue = length-1
        
        while white <= blue:
            if nums[blue] == 2:
                blue -= 1
            elif nums[white] == 0:
                nums[white], nums[red] = nums[red], nums[white]
                white += 1
                red += 1
            elif nums[white] == 2:
                nums[white], nums[blue] = nums[blue], nums[white]
                #white += 1
                blue -= 1
            else:
                white += 1
        return nums


if __name__ == '__main__':
    nums = [2, 0, 2, 1, 1, 0]
    assert (Solution().sortColors(nums) == [0, 0, 1, 1, 2, 2])
