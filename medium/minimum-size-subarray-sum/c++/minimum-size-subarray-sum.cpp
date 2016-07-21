// Brute force solution..
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minSize = INT_MAX;
        int currSum = 0;
        int curMinSize = 0;
        
        // if the array is empty
        if (nums.size() == 0)
            return 0;
        
        for(int i=0;i<nums.size();i++) {
            // smallest array if the number itself >=s
            if (nums[i] >= s)
                return 1;
            currSum = nums[i];
            for(int j=i+1; j<nums.size(); j++) {
                currSum = currSum + nums[j];
                if (currSum >= s) {
                    curMinSize = j - i + 1;
                    break;
                }
            }
            // if you never found the  sum, in one iteration then return 0
            if (curMinSize == 0)
                return 0;
            if (curMinSize<minSize)
                minSize = curMinSize;
        }
        return minSize;
    }
};

// Optimal solution

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, len = nums.size(), start = 0;
        bool flag = false;
        for (int i = 0; i < nums.size(); ++i) {
            // smallest subarray possible.
            if (nums[i] >= s)
                return 1;
            sum += nums[i];
            while (sum >= s) {
                flag = true;
                len = min(len, i - start + 1);
                sum -= nums[start++];
            }
        }
        return flag ? len : 0;
    }
};
