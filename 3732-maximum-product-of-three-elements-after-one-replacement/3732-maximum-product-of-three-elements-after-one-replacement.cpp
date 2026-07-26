class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        //T.C = O(n log n) : sorting

        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long X = 100000; //10^5

        long long a = nums[0]; //smallest element
        long long b = nums[1]; //second smallest element
        long long c = nums[n - 2]; //second largest element
        long long d = nums[n - 1]; //largest element

        //2 largest positive numbers * X
        long long option1 = c * d * X;

        //2 smallest negative numbers * X
        long long option2 = a * b * X;

        //smallest negative and largest positive elements * -X
        long long option3 = - a * d * X;

        return max({option1, option2, option3});
    }
};