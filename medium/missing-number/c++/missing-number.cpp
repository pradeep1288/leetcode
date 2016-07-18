class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() != nums.back())
            return nums.back() + 1;
        if (nums.front() != 0)
            return 0;
            
        int sum = 0;
        
        for (auto i: nums)
            sum += i;
        int actual_sum = (nums.back()*(nums.back() + 1))/2;
        
        return actual_sum - sum;
    }
};
