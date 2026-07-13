class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        //BFS   T.C = S.C. = O(1)

        queue<int> q;

        for(int i=1 ; i<=8 ; i++){
            q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            if(temp >= low && temp <= high) {
                ans.push_back(temp);
            }
            
            int last_digit = temp%10;
            if(last_digit + 1 <= 9) {
                q.push(temp * 10 +(last_digit + 1));
            }
        }
        
        return ans;

        
        /*


        //approach 2    T.C = S.C. = O(1)
        string s = "123456789";
        vector<int> ans;

        for (int len = 2; len <= 9; len++) {
            for (int start = 0; start <= 9 - len; start++) {
                int num = stoi(s.substr(start, len));
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
        */
    }
};