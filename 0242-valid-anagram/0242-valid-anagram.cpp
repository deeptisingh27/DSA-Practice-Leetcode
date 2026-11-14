class Solution {
public:
    bool isAnagram(string s, string t) {
        
        /*
        //T.C = O(n logn)

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s==t){
            return true;
        }
        else{
            return false;
        }

        */


        /*
        //T.C = O(n)

        if (s.length() != t.length()) return false;

        unordered_map<char, int> freq;

        // Count frequencies in s
        for (char ch : s) {
            freq[ch]++;
        }

        // Subtract frequencies using t
        for (char ch : t) {
            freq[ch]--;

            if (freq[ch] < 0) {
                return false; // More of char in t than s
            }
        }

        return true;
        */


        //T.C = O(n) , S.C = O(1)

        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);
        
        for (char ch : s) {
            freq[ch-'a']++;
        }

        for (char ch : t) {
            freq[ch-'a']--;
        }

        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
};