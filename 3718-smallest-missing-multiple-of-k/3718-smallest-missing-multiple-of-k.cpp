class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> seen(nums.begin(), nums.end());
        
        int curr_multiple = k;
        while(seen.count(curr_multiple)){ //seen.find(curr_multiple) != seen.end()
            curr_multiple += k;
        }

        return curr_multiple;
    }
};