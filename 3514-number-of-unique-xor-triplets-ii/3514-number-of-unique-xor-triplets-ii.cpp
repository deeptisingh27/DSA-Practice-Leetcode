class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        /*
        //APPROACH 1

        //store all unique pair XORs
        unordered_set<int> s1;
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                s1.insert(nums[i] ^ nums[j]);
            }
        }

        //find triplet XORs
        unordered_set<int> s2;
        for(int pairXor : s1){
            for(int &num : nums){
                s2.insert(pairXor ^ num);
            }
        }

        return s2.size();
        */


        //APPROACH 2

        int maxEl = *max_element(nums.begin(), nums.end());

        int T = 1; //T is the smallest power of 2 strictly greater than maxEl
        while(T <= maxEl){
            T = T << 1; // T = T*2;
        }

        vector<bool> s1(T, false); //XOR pair values set to true
        vector<bool> s2(T, false); //XOR triplet values set to true

        //mark all achievable pair XOR values in s1
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        //triplet XOR   
        for(int i=0 ; i<T ; i++){
            if(s1[i] == true){
                for(int &num : nums){
                    s2[i ^ num] = true;
                }
            }
        }

        //count total number of unique valid triplet XOR values marked in s2
        int count = 0; 
        for(int i=0 ; i<T ; i++){
            if(s2[i] == true){
                count++;
            }
        }

        return count;
    }
};