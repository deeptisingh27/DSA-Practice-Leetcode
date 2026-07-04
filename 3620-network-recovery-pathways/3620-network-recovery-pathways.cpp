class Solution {
public:
    typedef pair<long long, int> P;

    //dijkstra's algoritm
    bool check(int mid, vector<vector<pair<int,int>>> &adj, long long k, int n) {

        //dist[i] = min. cost path from source to ith node
        vector<long long> dist(n, LLONG_MAX);

        //min. heap for dijkstra's algo
        priority_queue<P, vector<P>, greater<P>> pq;
        
        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n-1) 
                return d<=k;

            //total cost reaching source to node d
            if(dist[node] < d) continue;

            if (d > k) continue;

            for(auto &vec : adj[node]){
                int ngbr = vec.first;
                int cost = vec.second;

                if(cost < mid) continue;

                if(d+cost < dist[ngbr]){
                    dist[ngbr] = d+cost;
                    pq.push({d+cost, ngbr});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        //T.C. = O(log(r-l) * E logV)

        //maximize the minimum -> Binary Search on answer

        int n = online.size();

        vector<vector<pair<int, int>>> adj(n); //adjacency list
        int l = INT_MAX;
        int r = 0;

        // Build graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            if (v != n - 1 && !online[v]) continue;

            adj[u].push_back({v, cost});
            l = min(l, cost);
            r = max(r, cost);
        }

        int ans = -1;

        // Binary search on the maximum possible minimum edge cost
        while (l <= r) { //O(log(r-l))
            int mid = l + (r - l) / 2; //mid score

            if (check(mid, adj, k, n)) { //O(E logV)
                ans = mid;
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }        

        return ans;
    }
};