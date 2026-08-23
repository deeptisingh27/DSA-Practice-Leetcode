class Solution {
public:
    bool sumGame(string num) {
        //T.C = O(n) , S.C = O(1)
        
        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;

        int leftQnMark = 0;
        int rightQnMark = 0;

        for(int i=0 ; i<n ; i++){
            if(num[i] == '?'){
                if(i < n/2) leftQnMark ++;
                else rightQnMark++;
            }

            else{
                if(i < n/2) leftSum += num[i] - '0';
                else rightSum += num[i] - '0';
            }
        }

        int totalQnMark = leftQnMark + rightQnMark;
        if(totalQnMark % 2 == 1){ //odd ?: alice always wins
            return true;
        }

        int left = 2 * leftSum + 9 * leftQnMark;
        int right = 2 * rightSum + 9 * rightQnMark;

        if(left == right){ //bob wins
            return false;
        }
        else{
            return true;
        }
    }
};