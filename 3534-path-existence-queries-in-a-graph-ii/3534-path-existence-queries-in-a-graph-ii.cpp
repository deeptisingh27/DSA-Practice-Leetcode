class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        
        
        // 1. Sort nodes by value
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());

        vector<int> sortedVal(n);
        vector<int> pos(n); // pos[originalNode] = position in sorted order
        for (int i = 0; i < n; i++) {
            sortedVal[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        // 2. Component id for each sorted position (merge if gap <= maxDiff)
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1] + ((sortedVal[i] - sortedVal[i - 1] > maxDiff) ? 1 : 0);
        }

        // 3. far[i] = farthest sorted index reachable directly from i (two pointer)
        vector<int> far(n);
        {
            int r = 0;
            for (int i = 0; i < n; i++) {
                if (r < i) r = i; // ensure far[i] >= i (self reachable)
                while (r + 1 < n && sortedVal[r + 1] - sortedVal[i] <= maxDiff) r++;
                far[i] = r;
            }
        }

        // 4. Binary lifting table over far[]
        const int LOG = 18; // 2^17 > 1e5, safe margin
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = far;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][ up[k - 1][i] ];
            }
        }

        // 5. Answer queries
        int qn = queries.size();
        vector<int> ans(qn);
        for (int i = 0; i < qn; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (u == v) { ans[i] = 0; continue; }

            int pu = pos[u], pv = pos[v];
            if (comp[pu] != comp[pv]) { ans[i] = -1; continue; }

            int a = min(pu, pv), b = max(pu, pv);
            int cur = a, steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }
            // one final jump to reach/exceed b
            cur = far[cur];
            steps += 1;

            ans[i] = steps;
        }

        return ans;
    }
};