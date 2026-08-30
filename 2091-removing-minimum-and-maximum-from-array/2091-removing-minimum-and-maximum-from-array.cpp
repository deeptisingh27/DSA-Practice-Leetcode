class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        // int min_idx = min_element(nums.begin(), nums.end() - nums.begin());
        // int max_idx = max_element(nums.begin(), nums.end() - nums.begin());

        int min_idx = 0;
        int max_idx = 0;

        for(int i=1 ; i<n ; i++){
            if(nums[i] < nums[min_idx])
                min_idx = i;

            if(nums[i] > nums[max_idx])
                max_idx = i;
        }

        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);

        //both deletions from front
        int option1 = right + 1;

        //both deletions from back
        int option2 = n - left;

        //left deletion from front, right deletion from back
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};