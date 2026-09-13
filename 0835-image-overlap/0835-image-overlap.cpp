class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect positions of 1s in both images
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.emplace_back(r, c);
                if (img2[r][c] == 1) ones2.emplace_back(r, c);
            }
        }

        // Count shift vector frequencies
        // Shift range for dr and dc is [-(n-1), n-1], mapped to [0, 2n] for fast indexing
        vector<vector<int>> count(2 * n + 1, vector<int>(2 * n + 1, 0));
        int maxOverlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int dr = r2 - r1 + n;
                int dc = c2 - c1 + n;
                maxOverlap = max(maxOverlap, ++count[dr][dc]);
            }
        }

        return maxOverlap;
    }
};