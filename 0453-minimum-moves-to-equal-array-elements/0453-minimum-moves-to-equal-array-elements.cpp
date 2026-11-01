class Solution {
public:
    int minMoves(vector<int>& nums) {
        //minimum value in the array
        int mini = nums[0];
        for (int x : nums) {
            if (x < mini) {
                mini = x;
            }
        }

        //sum the difference between each number and the minimum
        long long count = 0;
        for (int x : nums) {
            count += (x - mini);
        }

        return count;
    }
};