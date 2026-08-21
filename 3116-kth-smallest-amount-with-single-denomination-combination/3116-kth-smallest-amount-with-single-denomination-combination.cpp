class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        // Helper to count multiples <= m using Inclusion-Exclusion Principle
        auto countMultiples = [&](long long m) -> long long {
            long long cnt = 0;
            // Iterate over all non-empty subsets using bitmask
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int bits = 0;
                bool overflow = false;
                
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        bits++;
                        current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                        if (current_lcm > m) {
                            overflow = true;
                            break;
                        }
                    }
                }
                
                if (!overflow) {
                    if (bits % 2 == 1) {
                        cnt += m / current_lcm;
                    } else {
                        cnt -= m / current_lcm;
                    }
                }
            }
            return cnt;
        };

        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};