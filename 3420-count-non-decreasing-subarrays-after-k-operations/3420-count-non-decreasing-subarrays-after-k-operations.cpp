class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        
        // Monotonic decreasing deque storing {running_max_value, count_of_elements}
        deque<pair<int, int>> dq;
        int r = n - 1;
        
        for (int l = n - 1; l >= 0; --l) {
            int count = 1;
            // Merge all blocks at the front that are <= nums[l]
            while (!dq.empty() && dq.front().first <= nums[l]) {
                auto [val, cnt] = dq.front();
                dq.pop_front();
                cost += 1LL * (nums[l] - val) * cnt;
                count += cnt;
            }
            dq.push_front({nums[l], count});
            
            // Shrink window from the right until cost <= k
            while (cost > k) {
                cost -= (dq.back().first - nums[r]);
                if (--dq.back().second == 0) {
                    dq.pop_back();
                }
                --r;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};