class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        //change the two smallest elements
        int opt1 = nums[n-1] - nums[2];

        //change the two largest elements
        int opt2 = nums[n-3] - nums[0];

        //change the smallest and largest elements
        int opt3 = nums[n-2] - nums[1];
        
        return min({opt1, opt2, opt3});
    }
};