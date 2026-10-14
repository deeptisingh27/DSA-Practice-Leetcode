class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        //T.C = O(num) , S.C = O(1)
        
        if(sum > num * 9)
            return "";

        int nines = sum/9;
        int remain = sum%9;

        string ans(nines, '9');

        if(remain>0) 
            ans.push_back(remain + '0');

        int zeros = num - ans.length();
        ans.append(zeros, '0');

        return ans;
    }
};