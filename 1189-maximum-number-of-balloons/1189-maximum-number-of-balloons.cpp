class Solution {
public:
    int maxNumberOfBalloons(string text) {

        //T.C = O(n) , S.C = O(1)

        vector<int> freq(26, 0);

        for(char ch : text){
            freq[ch-'a']++;
        }

        int count = INT_MAX;
        
        //b a ll oo n
        count = min(count, freq['b'-'a']);
        count = min(count, freq['a'-'a']);
        count = min(count, freq['l'-'a'] / 2);
        count = min(count, freq['o'-'a'] / 2);
        count = min(count, freq['n'-'a']);

        return count;
    }
};