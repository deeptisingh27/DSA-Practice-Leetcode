class Solution {
public:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Structure to preserve original index and precompute digit sum
        struct Item {
            int digit_sum;
            int val;
            int orig_idx;
        };

        vector<Item> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {getDigitSum(nums[i]), nums[i], i};
        }

        // Sort based on the specified criteria
        sort(arr.begin(), arr.end(), [](const Item& a, const Item& b) {
            if (a.digit_sum != b.digit_sum) {
                return a.digit_sum < b.digit_sum;
            }
            return a.val < b.val;
        });

        // Find cycle lengths to compute minimum swaps
        vector<bool> visited(n, false);
        int total_swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].orig_idx == i) {
                continue;
            }

            int cycle_length = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].orig_idx;
                cycle_length++;
            }

            if (cycle_length > 1) {
                total_swaps += (cycle_length - 1);
            }
        }

        return total_swaps;
    }
};