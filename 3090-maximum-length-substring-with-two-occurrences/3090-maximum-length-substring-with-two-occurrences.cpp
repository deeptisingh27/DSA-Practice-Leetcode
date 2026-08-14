class Solution {
public:
    int maximumLengthSubstring(string s) {
        //sliding window

        int n = s.size();
        int freq[26] = {0};

        int i = 0;
        int j = 0;

        int ans = 0;

        for(j=0 ; j<n ; j++){
            freq[s[j] - 'a']++;

            //if any character appears more than twice, shrink from the left
            while(freq[s[j] - 'a'] > 2){
                freq[s[i] - 'a']--;
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};