class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret =0, max_ending_here =0, min_ending_here =0;
        if (nums.size() == 1)
            return nums[0];
        for(int i=0; i < nums.size(); i++) {
             if ( nums[i] < 0 )  {  
                int temp = min_ending_here;
                min_ending_here = min ( max_ending_here * nums[i], nums[i] );
                max_ending_here = max ( temp * nums[i], nums[i] );
            } else {
                min_ending_here = min ( min_ending_here * nums[i], nums[i] );
                max_ending_here = max ( max_ending_here * nums[i], nums[i] );
            }  
            ret = max (ret, max_ending_here);
        }
        return ret;
    }
};
