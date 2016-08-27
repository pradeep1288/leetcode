class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> numCount;
        vector<int> result; 
        if (nums1.size() == 0 || nums2.size() == 0)
            return result;

        for (auto num: nums1) 
            numCount[num] = 1;
        for (auto num: nums2)
            if (numCount[num])
                numCount[num]++;
        for (auto it = numCount.begin(); it != numCount.end(); it++) 
            if (it->second > 1)
                result.push_back(it->first);
                
        return result;
    }
};
