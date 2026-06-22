class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int n = text.size();

        vector<int> freq(26, 0);

        for(char ch : text){
            freq[ch-'a']++;
        }

        int count = INT_MAX;
        
        count = min(count, freq['b'-'a']);
        count = min(count, freq['a'-'a']);
        count = min(count, freq['l'-'a'] / 2);
        count = min(count, freq['o'-'a'] / 2);
        count = min(count, freq['n'-'a']);

        return count;
    }
};