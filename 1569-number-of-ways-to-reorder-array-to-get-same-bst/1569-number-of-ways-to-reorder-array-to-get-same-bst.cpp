class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    void precomputeComb(int n) {
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long waysLeft = dfs(left);
        long long waysRight = dfs(right);

        int l = left.size();
        int r = right.size();

        long long waysCombine = comb[l + r][l];
        long long totalWays = (waysCombine * waysLeft) % MOD;
        totalWays = (totalWays * waysRight) % MOD;

        return totalWays;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputeComb(n);
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};