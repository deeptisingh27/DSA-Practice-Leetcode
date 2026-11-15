class Solution {
public:
    int firstUniqChar(string s) {
        /*
        //BRUTE FORCE   

        int count=0;
        
        for(int i=0 ; i<s.size() ; i++){
            bool isUnique = true;

            for(int j=0 ; j<s.size() ; j++){

                while(i != j && s[i] == s[j]){
                    isUnique = false;
                    break;
                }
            }

            if (isUnique){
                return i;
            }
        }

        return -1;
        */


        /*
        unordered_map<char,int> mp;
        queue<int> q; //stores unique element only

        for(int i=0 ; i<s.size() ; i++){
            if(mp.find(s[i]) == mp.end()){ //s[i] exist krta nhi map me
                q.push(i);
            }
            mp[s[i]]++;

            //removing all repeting vales from queue
            while(q.size() > 0 && mp[s[q.front()]] > 1){
                q.pop();
            }
        }
        //agr q empty ho jaye toh return -1 else front element of q
        return q.empty() ? -1 : q.front(); 
        */


        /*
        int arr[26] = {0};

        for(int i=0 ; i<s.size() ; i++){
            char ch = s[i];
            arr[ch-'a']++;
        }

        for(int i=0 ; i<s.size() ; i++){
            char ch = s[i];
            if(arr[ch-'a'] == 1){
                return i;
            }
        }        
        return -1;
        */



        unordered_map<char, int> freq;

        // First pass: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Second pass: Find index of first unique character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};