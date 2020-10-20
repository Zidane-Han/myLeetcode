class Solution {
public:
    bool canReachZero(vector<int>& arr, int index, vector<bool>& visited) {
        if (index >= arr.size() || index < 0 || visited[index]) {
            return false;
        }
        
        if (arr[index] == 0)   return true;
        
        visited[index] = true;
        return canReachZero(arr, index-arr[index], visited) || canReachZero(arr, index+arr[index], visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        vector<bool> visited(len, false);
        
        return canReachZero(arr, start, visited);
    }
};