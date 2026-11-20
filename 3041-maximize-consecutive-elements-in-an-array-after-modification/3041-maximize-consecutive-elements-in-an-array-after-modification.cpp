class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // dp[v] stores the max length of a consecutive sequence ending at value v
        unordered_map<int, int> dp;
        int max_len = 0;
        
        for (int x : nums) {
            // Update x + 1 first so it doesn't reuse the current element x
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            
            max_len = max({max_len, dp[x], dp[x + 1]});
        }
        
        return max_len;
    }
};