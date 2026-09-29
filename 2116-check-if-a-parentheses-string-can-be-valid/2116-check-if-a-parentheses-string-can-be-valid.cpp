class Solution {
public:
    bool canBeValid(string s, string locked) {
        //T.C = O(n) , S.C = O(1)

        int n = s.length();
        
        //valid parentheses string must have an even length
        if (n%2 != 0) return false;
        
        // Pass 1: Left to right (check for excessive locked ')')
        int open_or_unlocked = 0;
        for (int i=0 ; i<n ; ++i) {
            if (locked[i] == '0' || s[i] == '(') {
                open_or_unlocked++;
            } 
            else {
                open_or_unlocked--;
            }

            if (open_or_unlocked < 0) {
                return false;
            }
        }

        // Pass 2: Right to left (check for excessive locked '(')
        int close_or_unlocked = 0;
        for (int i = n-1 ; i>=0 ; --i) {
            if (locked[i] == '0' || s[i] == ')') {
                close_or_unlocked++;
            } 
            else {
                close_or_unlocked--;
            }
            
            if (close_or_unlocked < 0) {
                return false;
            }
        }

        return true;
    }
};