class Solution {
public:
    /*
    int t[100001];

    int solve(int n, vector<int>& prefixSum, int i){
        if(i == n-1){
            return prefixSum[n-1];
        }

        if(t[i] != -1){
            return t[i];
        }

        int take = prefixSum[i] - solve(n, prefixSum, i+1); //now bob's turn
        int skip = solve(n, prefixSum, i+1);

        return t[i] = max(take, skip);
    }
    */

    int stoneGameVIII(vector<int>& stones) {
        //TOP DOWN DP(recursion + memo) : gives TLE n 1 case

        /*
        int n = stones.size();

        memset(t, -1, sizeof(t));

        vector<int> prefixSum(n, 0);

        prefixSum[0] = stones[0];
        for(int i=1 ; i<n ; i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        return solve(n, prefixSum, 1); //alice's 1st turn
        */


        //BOTTOM UP DP

        int n = stones.size();

        vector<int> prefixSum(n, 0);

        prefixSum[0] = stones[0];
        for(int i=1 ; i<n ; i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        vector<int> t(n, 0);
        t[n-1] = prefixSum[n-1];

        for(int i=n-2 ; i>=1 ; i--){
            int take = prefixSum[i] - t[i+1];
            int skip = t[i+1];

            t[i] = max(take, skip);
        }

        return t[1];
    }
};