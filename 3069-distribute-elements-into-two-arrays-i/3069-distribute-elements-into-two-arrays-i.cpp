class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        //T.C = O(n) = S.C

        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};

        for(int i=2 ; i<nums.size() ; i++){
            if (arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            
            else
                arr2.push_back(nums[i]);
        }

        //concatenate arr2 at the end of arr1 and return arr1
        arr1.insert(arr1.end(), arr2.begin(), arr2.end()); 
        return arr1;
    }
};