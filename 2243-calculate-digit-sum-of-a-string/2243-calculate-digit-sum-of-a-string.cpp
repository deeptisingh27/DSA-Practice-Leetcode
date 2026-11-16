class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_s = "";
            
            // Iterate through the string in steps of size k
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                
                // Sum up to k digits, making sure not to go out of bounds
                for (int j = i; j < i + k && j < s.length(); ++j) {
                    sum += s[j] - '0';
                }
                
                next_s += to_string(sum);
            }
            
            s = next_s;
        }
        
        return s;
    }
};