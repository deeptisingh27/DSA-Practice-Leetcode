class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //T.C = O(n log n)

        /*
        vector<int> ans;

        for(int n : nums){
            ans.push_back(n*n);
        }

        sort(ans.begin(),ans.end());

        return ans;
        */

        
        //Approach: Two Pointers
        //T.C = O(n)

        int n = nums.size();

        vector<int> ans(n);

        int left = 0, right = n-1;
        int index = n-1;

        while(left <= right) {
            int l = nums[left] * nums[left];
            int r = nums[right] * nums[right];

            if(l > r) {
                ans[index] = l;
                left++;
            }
            else {
                ans[index] = r;
                right--;
            }

            index--;
        }

        return ans;
    }
};