class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; //update minimum price so far
            } 
            else {
                ans = max(ans, price - minPrice); //check profit
            }
        }

        return ans;

    }
};