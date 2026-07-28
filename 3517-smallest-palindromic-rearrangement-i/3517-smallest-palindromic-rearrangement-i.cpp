class Solution {
public:
    string smallestPalindrome(string s) {
        //T.C = O(n log n) , S.C = O(1)
        
        int n = s.size();
        int mid = n/2;

        //sort the first half
        sort(s.begin(), s.begin() + mid);

        //mirror the sorted first half onto the second half
        for (int i=0 ; i<mid ; i++) {
            s[n-1-i] = s[i];
        }

        return s;
    }
};