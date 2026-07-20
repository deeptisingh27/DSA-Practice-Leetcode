class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //T.C. = O(n) , S.C. = O(1)

        int n = nums.size();
        k %= n; //normalizing k

        reverse(nums.begin(), nums.end()); //Reverse the entire array
        reverse(nums.begin(), nums.begin() + k); //Reverse first k elements
        reverse(nums.begin() + k, nums.end()); //Reverse remaining elements
    }
};