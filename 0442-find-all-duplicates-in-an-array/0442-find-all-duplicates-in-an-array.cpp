class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;

        for (int i=0 ; i<nums.size() ; i++) {
            int index = abs(nums[i]) - 1; // Number ko 0-based index banao

            if (nums[index] < 0) {
                // Pehle se negative hai matlab ye duplicate hai!
                duplicates.push_back(abs(nums[i]));
            } else {
                // Pehli baar aaya hai toh isko negative mark kar do
                nums[index] = -nums[index];
            }
        }
        
        return duplicates;
    }
};