class Solution {
public:
    const int MOD = 1e9 + 7;

    // dp[i][j] = {maximum score, number of paths}
    vector<vector<pair<int, int>>> dp;

    // Check whether the current cell is inside the board and not an obstacle
    bool isValid(int i, int j, vector<string>& board, int n) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

    pair<int, int> solve(int i, int j, vector<string>& board, int n){
        //base case
        if(board[i][j] == 'E') return {0,1};

        if(dp[i][j] != make_pair(-1, -1)){
            return dp[i][j];
        }

        int upScore = -1, leftScore = -1, diagScore = -1;
        int upPaths = 0, leftPaths = 0, diagPaths = 0;

        char ch = board[i][j];

        // Move Up
        if (isValid(i - 1, j, board, n)) {
            auto [score, paths] = solve(i - 1, j, board, n);

            if (paths > 0) {
                upScore = score;
                upPaths = paths;

                if (ch >= '1' && ch <= '9')
                    upScore += ch - '0';
            }
        }

        // Move Left
        if (isValid(i, j - 1, board, n)) {
            auto [score, paths] = solve(i, j - 1, board, n);

            if (paths > 0) {
                leftScore = score;
                leftPaths = paths;

                if (ch >= '1' && ch <= '9')
                    leftScore += ch - '0';
            }
        }

        // Move Diagonal
        if (isValid(i - 1, j - 1, board, n)) {
            auto [score, paths] = solve(i - 1, j - 1, board, n);

            if (paths > 0) {
                diagScore = score;
                diagPaths = paths;

                if (ch >= '1' && ch <= '9')
                    diagScore += ch - '0';
            }
        }

        int bestScore = max({upScore, leftScore, diagScore});

        // No valid path exists
        if (bestScore == -1)
            return dp[i][j] = {0, 0};

        long long bestPaths = 0;

        if (upScore == bestScore)
            bestPaths = (bestPaths + upPaths) % MOD;

        if (leftScore == bestScore)
            bestPaths = (bestPaths + leftPaths) % MOD;

        if (diagScore == bestScore)
            bestPaths = (bestPaths + diagPaths) % MOD;

        return dp[i][j] = {bestScore, (int)bestPaths};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        //TOP DOWN DP
        //T.C : O(n^2) , S.C : O(n^2)
        
        int n = board.size();

        dp.assign(n, vector<pair<int,int>>(n, make_pair(-1, -1)));

        auto ans = solve(n-1, n-1, board, n);

        if(ans.second == 0)
            return {0,0};

        return {ans.first, ans.second};
    }
};