class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // mid ^ 1 flips the last bit:
            // - if mid is even, mid ^ 1 = mid + 1
            // - if mid is odd,  mid ^ 1 = mid - 1
            // So nums[mid] == nums[mid ^ 1] means mid is part of a valid pair
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;  // single element is in the right half
            } else {
                high = mid;     // single element is in the left half (or is mid)
            }
        }
        
        return nums[low];
    }
};