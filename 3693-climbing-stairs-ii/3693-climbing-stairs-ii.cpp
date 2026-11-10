class Solution {
public:
    long long solve(int i, vector<int>& costs, vector<long long>& dp){
        // Base case: at starting step 0, cost is 0
        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        long long min_prev = 2e18;

        // Try jumping from i-1, i-2, i-3
        for (int k=1 ; k<=3 ; k++) {
            if (i-k >= 0) {
                long long jump_cost = 1LL * k * k;
                min_prev = min(min_prev, solve(i-k, costs, dp) + jump_cost);
            }
        }

        // Add the cost of reaching step i (costs is 1-indexed, so costs[i - 1])
        return dp[i] = min_prev + costs[i-1];
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1, -1);
        return solve(n, costs, dp);
    }
};