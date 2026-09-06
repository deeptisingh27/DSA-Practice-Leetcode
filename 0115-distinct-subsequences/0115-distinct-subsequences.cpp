class Solution {
public:
    // int dp[1001][1001];

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

    /*
    int solvee(string &s, string &t, int m, int n){
        //base case 1
        if(n == 0) return dp[m][n] = 1; //found one subsequence

        //base case 2
        if(m == 0) return dp[m][n] = 0;

        if (dp[m][n] != -1) return dp[m][n];

        if(s[m-1] == t[n-1]){
            return dp[m][n] = solvee(s, t, m-1, n-1) + solvee(s, t, m-1, n);
        }
        else{
            return dp[m][n] =  solvee(s, t, m-1, n);
        }
    }
    */

    int numDistinct(string s, string t) {
        //APPROACH 1
        //top down(memo + recursion)
        /*
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
        */

        //APPROACH 2
        //Knapsack top down(easier to convert to bottom up)
        /*
        int m = s.length();
        int n = t.length();
        memset(dp, -1, sizeof(dp));
        return solvee(s, t, m, n);
        */

        //APPROACH 3
        //bottom up(using knapsack)
        int m = s.length();
        int n = t.length();

        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1)); //dp array

        //base case 1 : dp[m][0] = 1
        // if(n == 0) return 1;
        for(int i=0 ; i<=m ; i++){
            dp[i][0] = 1;
        }

        //base case 2 : dp[0][n] = 0
        // if(m == 0) return 0;
        for(int i=1 ; i<=n ; i++){
            dp[0][i] = 0;
        }

        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }
};