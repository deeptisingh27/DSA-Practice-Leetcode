class Solution {
public:
    string largestGoodInteger(string num) {

        //T.C. = O(n) , S.C. = O(1)

        int n = num.length();
        string ans = "";
        
        for(int i=1 ; i<n-1 ; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                string curr(3, num[i]);   //creates ex: "777" of "7"

                ans = max(curr, ans);
            }
        }

        return ans;
    }
};