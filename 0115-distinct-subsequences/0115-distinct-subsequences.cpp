class Solution {
public:
    int dp[1001][1001];

    /*
    int solve(string &s, string &t, int i, int j){
        if(j == t.length()) return dp[i][j] = 1;
        if(i == s.length()) return dp[i][j] = 0;

        if (dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = solve(s, t, i+1, j+1) + solve(s, t, i+1, j);
        }
        else{
            return dp[i][j] = solve(s, t, i+1, j);
        }
    }
    */

    int solvee(string &s, string &t, int m, int n){
        if(n == 0) return dp[m][n] = 1; //found one subsequence
        if(m == 0) return dp[m][n] = 0;

        if (dp[m][n] != -1) return dp[m][n];

        if(s[m-1] == t[n-1]){
            return dp[m][n] = solvee(s, t, m-1, n-1) + solvee(s, t, m-1, n);
        }
        else{
            return dp[m][n] =  solvee(s, t, m-1, n);
        }
    }

    int numDistinct(string s, string t) {
        /*
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
        */

        //Knapsack (easier to convert to bottom up)
        int m = s.length();
        int n = t.length();
        memset(dp, -1, sizeof(dp));
        return solvee(s, t, m, n);
    }
};