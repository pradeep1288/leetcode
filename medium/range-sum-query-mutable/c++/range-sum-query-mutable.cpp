class SegTree {
    private:
        vector<int> tree;
    public:

        SegTree(vector<int> &nums) {
            int n = nums.size();
            if (n > 0) {
                tree.resize(4*n, 0);
                buildTree(nums, 0, 0, n-1);
            }
        }
        
        void buildTree(vector<int> &nums, int treeIndex, int lo, int hi) {
            if (lo == hi) {
                tree[treeIndex] = nums[lo];
                return;
            }
            int mid = lo + (hi-lo)/2;
            buildTree(nums, 2*treeIndex + 1, lo, mid);
            buildTree(nums, 2*treeIndex + 2, mid+1, hi);
            
            tree[treeIndex] = tree[2*treeIndex + 1] + tree[2*treeIndex + 2];
        } 
        
        int queryTree(int treeIndex, int lo, int hi, int i, int j) {
            if (hi < i  || lo > j)
                return 0;
            if (i<=lo && j >= hi) {
                return tree[treeIndex];
            }
            
            int mid = lo + (hi - lo)/2;
            
            if (i>mid) 
                return queryTree(2*treeIndex+2,mid+1, hi, i,j);
            else if (j<=mid)
                return queryTree(2*treeIndex+1, lo, mid,i,j);
            
            int leftQuery = queryTree(2*treeIndex+1, lo, mid, i, mid);
            int rightQuery = queryTree(2*treeIndex+2, mid+1, hi, mid+1,j);
            
            return leftQuery + rightQuery;
        }
        
        void updateTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
            if (lo == hi) {
                tree[treeIndex] = val;
                return;
            }
            
            int mid = lo + (hi-lo)/2;
            
            if (arrIndex > mid) 
                updateTree(2*treeIndex+2, mid+1, hi, arrIndex, val);
            else if (arrIndex<=mid)
                updateTree(2*treeIndex+1, lo, mid, arrIndex, val);
        
            tree[treeIndex] = tree[2*treeIndex+1] + tree[2*treeIndex+2];
        }
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        tree = new SegTree(nums);
        n = nums.size();
    }

    void update(int i, int val) {
        tree->updateTree(0,0,n-1,i,val);
    }

    int sumRange(int i, int j) {
        return tree->queryTree(0,0,n-1,i,j);
    }
private:
    SegTree *tree;
    int n;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
