class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAX_F = 1500;
        vector<int> freq(MAX_F + 1, 0);
        int min_price = INT_MAX;

        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, item[1]);
        }

        // Precompute total multiples for each factor (includes itself, so val = 1 + free_copies)
        vector<int> multiples_count(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; ++f) {
            if (freq[f] > 0) {
                for (int m = f; m <= MAX_F; m += f) {
                    multiples_count[f] += freq[m];
                }
            }
        }

        // 0/1 Knapsack for buying at least 1 copy of each item
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (const auto& item : items) {
            int factor = item[0];
            int price = item[1];
            if (price > budget) continue;

            int val = multiples_count[factor];
            for (int c = budget; c >= price; --c) {
                if (dp[c - price] != -1) {
                    dp[c] = max(dp[c], dp[c - price] + val);
                }
            }
        }

        // Spend any leftover budget on the cheapest item (+1 copy per min_price)
        int ans = 0;
        for (int c = 0; c <= budget; ++c) {
            if (dp[c] != -1) {
                int extra = (budget - c) / min_price;
                ans = max(ans, dp[c] + extra);
            }
        }

        return ans;
    }
};