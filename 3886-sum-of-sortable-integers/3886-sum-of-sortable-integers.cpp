class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        auto is_sortable = [&](int k) -> bool {
            int num_blocks = n / k;
            for (int b = 0; b < num_blocks; ++b) {
                int start = b * k;
                
                // Find drop points in nums[start ... start + k - 1]
                int drop_count = 0;
                int drop_idx = -1; // relative to start
                for (int j = 0; j < k - 1; ++j) {
                    if (nums[start + j] > nums[start + j + 1]) {
                        drop_count++;
                        drop_idx = j;
                    }
                }

                if (drop_count > 1) {
                    return false;
                }

                int shift = 0;
                if (drop_count == 1) {
                    // Elements wrap around, so the last element must be <= the first element
                    if (nums[start + k - 1] > nums[start]) {
                        return false;
                    }
                    shift = drop_idx + 1;
                }

                // Verify that rotating by `shift` matches sorted_nums
                for (int j = 0; j < k; ++j) {
                    if (nums[start + (shift + j) % k] != sorted_nums[start + j]) {
                        return false;
                    }
                }
            }
            return true;
        };

        long long total_sum = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (is_sortable(k)) {
                    total_sum += k;
                }
            }
        }

        return total_sum;
    }
};