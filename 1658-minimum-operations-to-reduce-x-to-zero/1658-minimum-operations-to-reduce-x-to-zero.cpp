class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long totalSum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long target = totalSum - x;

        // Removing all elements is exact
        if (target == 0) return nums.size();
        // Impossible to reach x
        if (target < 0) return -1;

        int left = 0;
        long long currentSum = 0;
        int maxLen = -1;

        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];

            // Shrink window if it exceeds target
            while (left <= right && currentSum > target) {
                currentSum -= nums[left++];
            }

            // Check if window matches target
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : static_cast<int>(nums.size()) - maxLen;
    }
};