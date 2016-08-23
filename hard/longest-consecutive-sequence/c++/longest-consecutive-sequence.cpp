class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n: nums) 
            s.insert(n);
        int res = 0;
        for(int i=0;i<nums.size();i++) {
            if (s.find(nums[i]-1) == s.end()) {
                int temp = nums[i];
                while(s.find(temp) != s.end()) {
                    temp++;
                }
                
                res = max(res, temp-nums[i]);
            }
        }
        return res;
    }
};
