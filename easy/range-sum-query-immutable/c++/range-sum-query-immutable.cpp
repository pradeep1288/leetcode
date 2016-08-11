class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (auto num: nums) {
            sum = sum + num;
            _allRanges.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return (i==0 ? _allRanges[j] : (_allRanges[j] - _allRanges[i-1]));    
    }
private:
    vector<int> _allRanges;
};
