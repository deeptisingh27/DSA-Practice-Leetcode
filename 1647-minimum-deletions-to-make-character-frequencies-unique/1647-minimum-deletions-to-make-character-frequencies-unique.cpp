class Solution {
public:
    int minDeletions(string s) {

        int count = 0;
        
        vector<int> freq(26, 0);
        for(char& ch : s){
            freq[ch - 'a']++;
        }

        unordered_set<int> used;

        for(int i=0 ; i<26 ; i++){
            while(freq[i] > 0 && used.find(freq[i]) != used.end()){
                freq[i]--;
                count++;
            }

            used.insert(freq[i]);
        }

        return count;
    }
};