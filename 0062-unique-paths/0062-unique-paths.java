class Solution {
    private int solve(int m, int n, int[][] dp) {
        if (m == 1 || n == 1) return 1;

        if (dp[m][n] != 0) return dp[m][n];

        // paths from top + paths from left
        return dp[m][n] = solve(m-1, n, dp) + solve(m, n-1, dp);
    }

    public int uniquePaths(int m, int n) {
        //TOP DOWN DP (recursion + memoization)
        int[][] dp = new int[m+1][n+1];

        return solve(m, n, dp);
    }
}