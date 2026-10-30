class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (n == 1) return 0;

        // Build adjacency list: u -> {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[u][count] stores the shortest distance to node u with `count`
        // consecutive identical characters matching labels[u].
        // 1-based indexing for count (ranges from 1 to k).
        vector<vector<int>> dist(n, vector<int>(k + 1, -1));

        // Min-priority queue: (cost, u, count)
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        // Starting at node 0 with streak = 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d > dist[u][count]) continue;

            // Target reached
            if (u == n - 1) {
                return d;
            }

            for (const auto& [v, w] : adj[u]) {
                int next_count = (labels[v] == labels[u]) ? (count + 1) : 1;

                if (next_count <= k) {
                    int next_dist = d + w;
                    if (dist[v][next_count] == -1 || next_dist < dist[v][next_count]) {
                        dist[v][next_count] = next_dist;
                        pq.push({next_dist, v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};