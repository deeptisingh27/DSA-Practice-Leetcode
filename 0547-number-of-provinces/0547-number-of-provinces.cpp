class Solution {
public:
    //khandaani DFS template
    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }

    //khandaani BFS template
    void BFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        queue<int> q;

        q.push(u);
        visited[u] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                if(!visited[v]){
                    BFS(adj, v, visited);
                }                
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //using DFS
        /*
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj; //make adjacency list

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                DFS(adj, i, visited);
                count++;
            }
        }

        return count;
        */


        //using BFS

        int n = isConnected.size();

        unordered_map<int, vector<int>> adj; //make adjacency list

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                BFS(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};