class Solution {
public:
    int getGCD(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int getLCM(int a, int b) {
        return (a / getGCD(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2; // Any 2 numbers always satisfy prod == lcm * gcd

        // Check every possible subarray starting at index i
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = nums[i];
            int l = nums[i];

            for (int j = i; j < n; j++) {
                prod *= nums[j];

                // Prevent integer overflow (max possible lcm * gcd is 25200)
                if (prod > 25200) {
                    break;
                }

                g = getGCD(g, nums[j]);
                l = getLCM(l, nums[j]);

                // Check if current subarray is product equivalent
                if (prod == (long long)l * g) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};