class Solution:
    
    def TwoCompare(self, n1, n2):
        if str(n1)+str(n2) < str(n2)+str(n1):
            return True
        else:
            return False
        
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        ## compare every two, str(nums1) + str(nums2) > str(nums2) + str(nums1)
        if len(nums) <= 1:
            return "".join(map(str, nums))
        
        nums.sort(key = lambda x: str(x)[0], reverse=False)
        
        # insertion sort
        for i in range(1, len(nums)):
            value = nums[i]
            point = i-1
            while point >= 0 and self.TwoCompare(nums[point], value):
                nums[point+1] = nums[point]
                point = point-1
            
            nums[point+1] = value
            
        # sorted list to string
        return str(int("".join(map(str, nums))))