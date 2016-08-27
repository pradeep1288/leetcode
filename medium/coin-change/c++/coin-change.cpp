class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        
        int num_coins = coins.size();
        
        // solution in solution[amount]
        int solution[amount+1];
        
        solution[0] = 0;
        
        for (int i=1;i<=amount;i++) {
            solution[i] = INT_MAX;
        }
        
        for (int i=1; i<=amount; i++) {
            for (int j=0; j<num_coins; j++) {
                if ( coins[j] <= i) {
                    int sub_res = solution[i-coins[j]];
                    if (sub_res != INT_MAX && 1 + sub_res < solution[i]) {
                        solution[i] = 1 + sub_res;
                    }
                }
            }
        }
        if (solution[amount] == INT_MAX) 
            return -1;
        return solution[amount];
    }
};
