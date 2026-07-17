class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        /*
        //Brute Force : gives TLE
        //T.C. = , S.C. = 

        int n = nums.size();

        vector<int> gcdPairs;
        vector<int> answer;

        //generate all pairs
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                gcdPairs.push_back(__gcd(nums[i], nums[j]));
            }
        }

        sort(gcdPairs.begin(), gcdPairs.end());

        for(int i=0 ; i<queries.size() ; i++){
            answer.push_back(gcdPairs[queries[i]]);
        }

        return answer;
        */


        //T.C : O(n·sqrt(M) + M·log M + Q·log M) , where M = maxVal
        //S.C : O(M), M = maxVal

        int n = nums.size();
        int maxVal = *max_element(begin(nums), end(nums));

        vector<int> divisorFreq(maxVal+1, 0);

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            for(int j = 1; j*j <= num; j++) {

                if(num % j == 0) {
                    divisorFreq[j]++;

                    if(num/j != j) {
                        divisorFreq[num/j]++;
                    }
                }
            }
        }

        vector<long long> pairsWithGcd(maxVal+1, 0);

        for(int g = maxVal; g >= 1; g--) {
            long long count = divisorFreq[g];
            
            pairsWithGcd[g] = count * (count-1)/2;

            for(int mult = 2*g; mult <= maxVal; mult += g) {
                pairsWithGcd[g] -= pairsWithGcd[mult];
            }    
        }

        vector<long long> prefixCountGcd(maxVal+1, 0);

        for(int g = 1; g <= maxVal; g++) {
            prefixCountGcd[g] = prefixCountGcd[g-1] + pairsWithGcd[g];
        }

        vector<int> ans;

        for(long long idx : queries){
            int l = 1;
            int r = maxVal;
            int temp = 1;

            while(l <= r){
                int mid_gcd = l + (r-l)/2;

                if(prefixCountGcd[mid_gcd] > idx) {
                    temp = mid_gcd;
                    r = mid_gcd-1;
                } 
                
                else {
                    l = mid_gcd+1;
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};