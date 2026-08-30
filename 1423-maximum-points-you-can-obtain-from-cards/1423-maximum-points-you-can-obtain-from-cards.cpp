class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //T.C = O(k) , S.C = O(1)

        int n = cardPoints.size();

        int frontScore = 0, backScore = 0;

        //initially take all k from front
        for(int i=0 ; i<k ; i++){
            frontScore += cardPoints[i];
        }

        int ans = frontScore;

        //gradually replace front cards with back cards
        for(int i=1 ; i<=k ; i++){
            frontScore -= cardPoints[k-i];
            backScore += cardPoints[n-i];

            ans = max(ans, frontScore + backScore);
        }

        return ans;
    }
};