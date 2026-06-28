class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        //T.C = O(n) , S.C = O(1)

        int n = nums.size();
        long long operations = 0;

        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i] <= nums[i+1]) //already sorted
                continue;
            
            int parts = nums[i] / nums[i+1];

            if(nums[i] % nums[i+1] != 0)
                parts++;

            operations += (parts-1);

            nums[i] = nums[i] / parts;
        }

        return operations;
    }
};