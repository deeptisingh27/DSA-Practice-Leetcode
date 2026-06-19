class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        //T.C : O(n) , S.C : O(1)

        int curr = 0;
        int maxAltitude = 0;

        for(int g : gain){
            curr += g;
            maxAltitude = max(maxAltitude, curr);
        }

        return maxAltitude;
    }
};