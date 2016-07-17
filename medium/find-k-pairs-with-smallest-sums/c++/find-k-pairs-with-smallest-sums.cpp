class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> _result;
         if (k == 0)
            return _result;
         if (nums1.size() == 0 || nums2.size() == 0)
            return _result;
        
        struct weightedPairs {
          pair<int,int> myPair;
          int sum;
        };
        
        
        struct Comp {
          bool operator()(const weightedPairs& A, const weightedPairs& B) {
              return (A.sum > B.sum);
          }   
        };
        
        vector<weightedPairs> customPairs;

        for (int i=0; i<nums1.size() && i<k; i++) {
            for (int j=0; j<nums2.size() && j<k; j++) {
                weightedPairs tempPair;
                tempPair.myPair = make_pair(nums1[i], nums2[j]);
                tempPair.sum = nums1[i] + nums2[j];
                customPairs.push_back(tempPair);
            }
        }
        
        std::make_heap(customPairs.begin(), customPairs.end(), Comp());
        int i = 0;
        int originalSize = customPairs.size();
        while (i<k) {
            if (i == originalSize)
                break;
            _result.push_back(customPairs.front().myPair);
            pop_heap(customPairs.begin(), customPairs.end(),Comp());
            customPairs.pop_back();
            i++;
        }
        return _result;
        
    }
};
