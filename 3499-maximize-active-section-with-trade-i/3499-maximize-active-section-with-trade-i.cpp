class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        // A trade bridges two adjacent '0' blocks by turning the '1' block between them into '0's, then converting the merged '0' block to all '1's
        //T.C = O(n) = S.C

        int n = s.size();

        int onesCount = 0;
        vector<int> zerosBlockSize;
        
        int i = 0;
        while(i < n){

            //counting total '1's
            if(s[i] == '1'){
                onesCount++;
                i++;
            }

            //lengths of all contiguous '0' blocks
            else{ //s[i] == '0'
                int start = i;
                while(i<n && s[i] == '0') i++;

                zerosBlockSize.push_back(i-start);
            }
        }
        
        int maxPairSum = 0;
        for(int i=1 ; i<zerosBlockSize.size() ; i++){
            maxPairSum = max(maxPairSum, zerosBlockSize[i] + zerosBlockSize[i-1]);
        }

        //Total active sections = Original '1's + Max gain from merging 2 adjacent '0' blocks
        return onesCount + maxPairSum; 
    }
};