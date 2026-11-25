class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Two large prime moduli and bases for collision-resistant double hashing
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 1315423911ULL % MOD1;
        const uint64_t BASE2 = 2654435761ULL % MOD2;

        // Precompute powers of BASE1 and BASE2
        vector<uint64_t> p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            p1[i] = (p1[i - 1] * BASE1) % MOD1;
            p2[i] = (p2[i - 1] * BASE2) % MOD2;
        }

        // Helper lambda to check if there is at least one unique subarray of length L
        auto hasUnique = [&](int L) -> bool {
            uint64_t h1 = 0, h2 = 0;
            for (int i = 0; i < L; ++i) {
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;
            }

            unordered_map<uint64_t, int> freq;
            freq.reserve(n - L + 1);
            freq[(h1 << 32) | h2]++;

            for (int i = L; i < n; ++i) {
                // Remove leading element nums[i - L]
                h1 = (h1 + MOD1 - (nums[i - L] * p1[L - 1]) % MOD1) % MOD1;
                h2 = (h2 + MOD2 - (nums[i - L] * p2[L - 1]) % MOD2) % MOD2;

                // Append trailing element nums[i]
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;

                freq[(h1 << 32) | h2]++;
            }

            for (const auto& [hashVal, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        // Binary search on the answer L
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};