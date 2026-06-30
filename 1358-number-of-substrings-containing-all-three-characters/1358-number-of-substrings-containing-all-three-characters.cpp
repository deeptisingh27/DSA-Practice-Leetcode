class Solution {
public:
    int numberOfSubstrings(string s) {

        /*

        //brute force : gives TLE
        //T.C. = O(n^2)

        int n = s.size();
        int count = 0;

        // Generate all substrings
        for (int i=0 ; i<n ; i++) {
            vector<int> freq(3, 0); // freq[0] -> a, freq[1] -> b, freq[2] -> c

            for (int j=i ; j<n ; j++) {

                freq[s[j] - 'a']++;

                // Check if current substring contains a, b and c
                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
                    count++;
            }
        }

        return count;

        */

        //when thers is some criteria for extracting the substring -> SLIDING WINDOW
        //T.C. = O(n)

        int n = s.size();
        int count = 0;

        vector<int> freq(3, 0); //0-1 , 1-b , 2-c

        int i = 0;
        int j = 0;        

        while(j<n) {
            char ch = s[j];

            freq[ch-'a']++;

            // Shrink window while it contains all 3 characters
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

                // All substrings ending from right to n-1 are valid
                count += (n - j);

                // Remove leftmost character
                freq[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return count;
        
    }
};