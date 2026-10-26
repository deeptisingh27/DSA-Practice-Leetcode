class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long island_sum = 0;
                    queue<pair<int, int>> q;

                    // Initialize BFS from the starting cell
                    q.push({i, j});
                    island_sum += grid[i][j];
                    grid[i][j] = 0; // Mark as visited

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (const auto& dir : directions) {
                            int nr = r + dir[0];
                            int nc = c + dir[1];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                island_sum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark as visited
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (island_sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};