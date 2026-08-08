class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        
        vector<int> ans(n2);
        vector<int> last(n2, -1);
        
        // Precompute the last occurrence index in word1 for each character in word2 from the right
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }
        
        bool canSkip = true;
        j = 0;
        
        // Greedily build the result sequence from left to right
        for (i = 0; i < n1; ++i) {
            if (j == n2) break;
            
            if (word1[i] == word2[j]) {
                ans[j++] = i;
            } else if (canSkip && (j == n2 - 1 || i < last[j + 1])) {
                canSkip = false;
                ans[j++] = i;
            }
        }
        
        // Return result if all characters of word2 are matched, otherwise empty array
        return j == n2 ? ans : vector<int>();
    }
};