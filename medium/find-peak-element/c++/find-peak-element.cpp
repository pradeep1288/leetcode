class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return searchPeakElement(0, nums.size()-1, nums);
    }
    
    int searchPeakElement(int low, int high, vector<int>& nums) {
        int mid = low +(high-low)/2;
        
        // if the middle element is greater than or equal to its neighbours then return the middle element
        if ((mid == 0 || nums[mid-1] <= nums[mid]) && (mid == nums.size()-1 || nums[mid+1]<=nums[mid])) 
            return mid;
        // if the left of middle element is greater than the middle element then search the left
        else if (mid > 0 && nums[mid-1] > nums[mid])
            return searchPeakElement(low, mid-1, nums);
        // if the right of the middle element is greater than the middle then search the right
        else 
            return searchPeakElement(mid+1 , high, nums);
    }
};
