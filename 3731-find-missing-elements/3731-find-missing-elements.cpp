class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        //T.C = O(n + (maxi-mini+1)) , S.C = O(n) (excluding the output array)
    
        unordered_set<int> numss(nums.begin(), nums.end()); //O(n)

        /*
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] > maxi) maxi = nums[i];
            if(nums[i] < mini) mini = nums[i];
        }
        */

        int mini = *min_element(nums.begin(), nums.end()); //O(n)
        int maxi = *max_element(nums.begin(), nums.end()); //O(n)

        vector<int> ans;
        for(int i=mini ; i<=maxi ; i++){ //O(maxi-mini+1)
            if(numss.find(i) == numss.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};