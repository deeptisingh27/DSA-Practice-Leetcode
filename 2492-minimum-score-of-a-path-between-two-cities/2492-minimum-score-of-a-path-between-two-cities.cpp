class Solution {
public:
    void dfs(int u, unordered_map<int, vector<pair<int, int>>>& adj, vector<bool> &visited, int &ans) {

        visited[u] = true;

        for(auto &it : adj[u]) {
            int v = it.first;
            int d = it.second;

            // Update the minimum edge seen so far
            ans = min(ans, d);

            if(!visited[v]) {
                dfs(v, adj, visited, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        // DFS : O(V+E)
        // Adjacency list -> {neighbor, distance}
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> visited(n, false);

        int ans = INT_MAX;

        // Traverse the connected component containing city 1
        dfs(1, adj, visited, ans);

        return ans;
    }
};