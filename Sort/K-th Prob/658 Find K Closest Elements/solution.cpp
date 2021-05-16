class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        int left = 0;
        int right = k;  // the next of the k-th closest int
        
        while (right < len) {
            if (abs(arr[right] - x) > abs(arr[left] - x)) {
                break;
            } else if (abs(arr[right] - x) == abs(arr[left] - x) && arr[right] != arr[left]) {
                break;
            }
                
            left++;
            right++;
        }
        
        vector<int> res(arr.begin()+left, arr.begin() + right);
        return res;
    }
};