class Solution {
public:
    bool check(int minEdge, vector<vector<pair<int,int>>> &adj,
               vector<int> &topo, vector<bool> &online,
               long long k, int n) {

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) continue;

            for (auto &[v, cost] : adj[u]) {

                // Edge must satisfy the minimum edge score
                if (cost < minEdge) continue;

                // Intermediate nodes must be online
                if (v != n - 1 && !online[v]) continue;

                dist[v] = min(dist[v], dist[u] + cost);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            adj[u].push_back({v, cost});
            indegree[v]++;
            maxCost = max(maxCost, cost);
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, cost] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        int low = 0, high = maxCost;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, adj, topo, online, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};