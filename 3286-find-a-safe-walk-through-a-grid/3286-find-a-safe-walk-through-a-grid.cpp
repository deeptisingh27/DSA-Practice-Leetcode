class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}}; //right,down,left,up

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        //cheapest/shortest path from source to one/multiple destination -> DIJKSTRA
        //edge weights are only 0 and 1, so 0-1 BFS finds the shortest path in O(V + E), which is faster than using Dijkstra's algorithm (O(E log V))

        //0-1 BFS
        //T.C. = O(m * n) = S.C.

        int m = grid.size(); //row
        int n = grid[0].size(); //col

        //dist[i][j] = min. health to reach from [0][0] to [i][j]
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); 

        deque<pair<int,int>> dq;

        dist[0][0] = grid[0][0]; //source is[0,0]
        dq.push_front({0,0});

        while(!dq.empty()){

            auto [r,c] = dq.front(); //r-> row, c->column
            dq.pop_front();

            for(auto &dir : directions){

                int nc = c + dir.first;
                int nr = r + dir.second;

                if(nr<0 || nc<0 || nr>=m || nc>=n)
                    continue;

                int newCost = dist[r][c] + grid[nr][nc];

                if(newCost < dist[nr][nc]){

                    dist[nr][nc] = newCost;

                    if(grid[nr][nc] == 0)
                        dq.push_front({nr,nc});
                    else
                        dq.push_back({nr,nc});
                }
            }
        }

        int x = dist[m-1][n-1];

        return health-x >= 1; //return x < health;
    }
};