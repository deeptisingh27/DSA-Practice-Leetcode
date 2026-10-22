class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Step 1: Find where '0' is sitting
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        // Step 2: Check if numbers count up forward (0, 1, 2, ...)
        bool forward = true;
        for (int i = 0; i < n; i++) {
            if (nums[(p + i) % n] != i) {
                forward = false;
                break;
            }
        }

        // Step 3: Check if numbers count up backward (0, 1, 2, ...)
        bool backward = true;
        for (int i = 0; i < n; i++) {
            if (nums[(p - i + n) % n] != i) {
                backward = false;
                break;
            }
        }

        // If it's neither, it's impossible to sort
        if (!forward && !backward) return -1;

        // Step 4: Pick the smallest number of moves
        if (forward) {
            return min(p, n - p + 2);
        } else {
            return min(n - p, p + 2);
        }
    }
};