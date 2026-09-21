class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> result(k, 0);
        // dp[r] stores the number of subarrays ending at the current position with product % k == r
        vector<long long> dp(k, 0);

        for (int x : nums) {
            int val = x % k;
            vector<long long> next_dp(k, 0);

            // Extending existing subarrays
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * val) % k] += dp[r];
                }
            }

            // Starting a new subarray with just nums[j]
            next_dp[val] += 1;

            // Add the counts of subarrays ending at the current index to the total result
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return result;
    }
};