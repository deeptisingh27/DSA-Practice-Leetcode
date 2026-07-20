class Solution {
public:
    //function to reverse 2D grid using 1D indices
    void reverseGrid(vector<vector<int>>& grid, int i, int j, int n) {

        while (i < j){

            //mapping 1D index to 2D coordinates
            // /n gives the ROW index , %n gives the COLUMN index
            int r1 = i/n, c1 = i % n;
            int r2 = j/n, c2 = j % n;
            
            swap(grid[r1][c1], grid[r2][c2]);
            
            i++;
            j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        k %= total;

        reverseGrid(grid, 0, total - 1, n);
        reverseGrid(grid, 0, k - 1, n);
        reverseGrid(grid, k, total - 1, n);

        return grid;
    }
};