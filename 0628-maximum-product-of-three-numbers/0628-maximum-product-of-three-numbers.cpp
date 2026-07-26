class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        //T.C = O(n log n) : sorting

        int n = nums.size();

        sort(nums.begin(), nums.end());

        //3 largest positive numbers
        int option1 = nums[n-1] * nums[n-2] * nums[n-3];

        //2 smallest negative numbers * 1 largest positive number
        int option2 = nums[0] * nums[1] * nums[n-1];

        return max(option1, option2);
    }
};