/*
 *
 * [4] Median of Two Sorted Arrays
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int left = (len1 + len2 + 1) / 2;
        int right = (len1 + len2 + 2) / 2;
        
        return (findKthValue(nums1, 0, nums2, 0, left) + findKthValue(nums1, 0, nums2, 0, right)) / 2.0;
    }
    
    int findKthValue(vector<int>& nums1, int ptr1, vector<int>& nums2, int ptr2, int k) {
        if (ptr1 >= nums1.size()) {
            return nums2[ptr2 + k - 1];
        }
        if (ptr2 >= nums2.size()) {
            return nums1[ptr1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[ptr1], nums2[ptr2]);
        }
        
        int val1 = (ptr1 + k/2 - 1 < nums1.size()) ? nums1[ptr1 + k/2 - 1] : INT_MAX;
        int val2 = (ptr2 + k/2 - 1 < nums2.size()) ? nums2[ptr2 + k/2 - 1] : INT_MAX;
        
        if (val1 < val2) {
            return findKthValue(nums1, ptr1 + k/2, nums2, ptr2, k - k/2);
        } else {
            return findKthValue(nums1, ptr1, nums2, ptr2 + k/2, k - k/2);
        }   
    }
};