class Solution {
public:
    int minimumPushes(string word) {
        //T.C = O(n) , S.C = O(1)
        
        int n = word.length();
        int pushes = 0;

        for (int i = 0; i < n; i++) {
            // i/8 gives 0 for first 8 chars, 1 for next 8, so on
            pushes += (i / 8) + 1;
        }

        return pushes;
    }
};