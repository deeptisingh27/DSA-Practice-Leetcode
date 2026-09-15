class Solution {
    /*
    private int solve(int m, int n, int[][] dp) {
        if (m == 1 || n == 1) return 1;

        if (dp[m][n] != 0) return dp[m][n];

        // paths from top + paths from left
        return dp[m][n] = solve(m-1, n, dp) + solve(m, n-1, dp);
    }
    */

    public int uniquePaths(int m, int n) {
        //TOP DOWN DP (recursion + memoization)
        //T.C = O(m*n) = S.C

        /*
        int[][] dp = new int[m+1][n+1];

        return solve(m, n, dp);
        */

        //BOTTOM UP DP (recursion + memoization)
        //T.C = O(m*n) = S.C

        int[][] dp = new int[m][n];

        // only 1 way to reach any cell in the first column (all Down moves)
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // only 1 way to reach any cell in the first row (all Right moves)
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // Fill remaining cells 
        for (int i=1 ; i<m ; i++) {
            for (int j=1 ; j<n ; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
}