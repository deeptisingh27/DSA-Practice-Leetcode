class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        //T.C = O(num) , S.C = O(1)

        if(sum > num * 9)
            return "";

        int nines = sum/9;
        int remain = sum%9;

        //greedily place all 9s at positions to maximize the score
        string ans(nines, '9');

        //append the leftover remainder digit if one exists
        if(remain>0) 
            ans.push_back(remain + '0');

        //fill all remaining positions with zeros
        int zeros = num - ans.length();
        ans.append(zeros, '0');

        return ans;
    }
};