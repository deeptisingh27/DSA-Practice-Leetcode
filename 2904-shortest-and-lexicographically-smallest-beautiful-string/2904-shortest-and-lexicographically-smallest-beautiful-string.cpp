class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) { 

        //sliding window

        int n = s.length();
        
        int i=0;
        int j=0;
        int count = 0; //count of 1s in string

        string ans = "";        

        for(j=0 ; j<n ; j++){
            if(s[j] == '1')
                count++;

            // If we have more than k ones, shrink until count == k
            while(count > k){
                if(s[i] == '1') 
                    count--;

                i++;
            }

            // Once count == k, remove any redundant leading '0's
            while (count == k && s[i] == '0') {
                i++;
            }

            // Check if current valid window is shorter or lexicographically smaller
            if(count == k){
                string temp = s.substr(i, j-i+1);

                if(ans.empty() || ans.size() > j-i+1 || 
                (temp.length() == ans.length() && temp<ans)){
                    ans = temp;
                }
            }
        }    

        return ans;    
    }
};