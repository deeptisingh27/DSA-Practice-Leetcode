class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        //T.C = O(N logN) , S.C = O(1) 

        restrictions.push_back({1, 0}); //building 1 must have height 0
        restrictions.push_back({n, n-1}); //building n can have at most height n-1
 
        sort(restrictions.begin(), restrictions.end()); //O(N logN)

        int N = restrictions.size();

        //left to right
        for(int i=1 ; i<N ; i++) { //O(N)
            int diffDist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + diffDist);
        }

        //right to left
        for(int i = N-2 ; i >= 0 ; i--) { //O(N)
            int diffDist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + diffDist);
        }

        int ans = 0;

        for(int i=1 ; i<N ; i++) { //O(N)
            int leftPos = restrictions[i-1][0];
            int leftHt = restrictions[i-1][1];

            int currPos = restrictions[i][0];
            int currHt = restrictions[i][1];

            int d = currPos - leftPos; //distance between the two restricted buildings
            int htDiff = abs(leftHt - currHt); //difference in their heights

            int peak = max(leftHt, currHt) + (d - htDiff)/2;

            ans = max(ans, peak);
        }

        return ans;
    }
};