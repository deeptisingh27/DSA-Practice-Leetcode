class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;

        for (int i=0 ; i<s.length() ; i++) {
            int reversedAlphabetPos = 'z' - s[i] + 1;
            int stringPos = i + 1;
            total += reversedAlphabetPos * stringPos;
        }
        
        return total;
    }
};