class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0];
        for(int x : nums){
            if(x>maxi) maxi = x;
        }

        int moves = 0;
        for(int x : nums){
            moves += maxi - x;
        }

        return moves;
    }
};