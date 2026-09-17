class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        
        // min_len[i] stores the minimum length of a valid subarray in arr[0...i]
        vector<int> min_len(n, INF);
        
        int current_sum = 0;
        int left = 0;
        int ans = INF;
        int best_so_far = INF;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            // Shrink window from the left if current_sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            // Found a subarray with sum == target ending at right
            if (current_sum == target) {
                int curr_len = right - left + 1;

                // Check if there is a non-overlapping valid subarray ending at or before left - 1
                if (left > 0 && min_len[left - 1] != INF) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }

                best_so_far = min(best_so_far, curr_len);
            }

            min_len[right] = best_so_far;
        }

        return ans == INF ? -1 : ans;
    }
};