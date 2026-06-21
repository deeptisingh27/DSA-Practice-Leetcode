class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //T.C = O(n logn) , S.C. = O(1)
        
        sort(costs.begin(), costs.end());

        int count=0;

        for(int cost : costs){
            if(cost>coins) break;
            
            coins -= cost;
            count++;
        }

        return count;
    }
};