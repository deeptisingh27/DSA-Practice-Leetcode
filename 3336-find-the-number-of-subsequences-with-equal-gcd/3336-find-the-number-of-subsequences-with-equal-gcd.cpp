class Solution {
public:
    const int MOD = 1e9 + 7;

    int t[201][201][201];

    int solve(vector<int>& nums, int i, int first, int second){
        //base case
        if(i == nums.size()){
            bool bothNonEmpty = (first != 0 && second != 0);
            bool bothGcdMatch = (first == second);

            return (bothNonEmpty && bothGcdMatch) ? 1 : 0;
        }

        if(t[i][first][second] != -1){
            return t[i][first][second];
        }

        long long skip = solve(nums, i+1, first, second);
        long long take1 = solve(nums, i+1, __gcd(first, nums[i]), second);
        long long take2 = solve(nums, i+1, first, __gcd(second, nums[i]));

        return t[i][first][second] = (skip + take1 + take2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        //TOP DOWN DP (recur+memo)
        memset(t, -1, sizeof(t));

        return solve(nums, 0, 0, 0);
    }
};