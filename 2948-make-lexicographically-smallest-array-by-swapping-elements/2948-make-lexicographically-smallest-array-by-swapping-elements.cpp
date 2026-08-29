class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        //brute force : gives TLE
        /*
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            while(true){
                int smallVal = nums[i];
                int idx = -1;

                for(int j=i+1 ; j<n ; j++){
                    if(abs(nums[i] - nums[j]) <= limit){
                        if(nums[j] < smallVal){
                            smallVal = nums[j];
                            idx = j;
                        }
                    }
                }

                if(idx != -1){
                    swap(nums[i], nums[idx]);
                }
                else{
                    break;
                }
            }            
        }

        return nums;
        */


        int n = nums.size();

        vector<int> vec = nums;
        //sort the vec
        sort(vec.begin(), vec.end());

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]); 

        for(int i=1 ; i<n ; i++) {
            if(abs(vec[i] - vec[i-1]) > limit) {
                groupNum += 1;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }
        
        //Build the anwer - Merge the groups
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            //smallest available number in this group
            ans[i] = *groupToList[group].begin(); //use hogaya to delete kardo used element ko
            groupToList[group].pop_front();
        }

        return ans;
    }
};