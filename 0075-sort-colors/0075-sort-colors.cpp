class Solution {
public:
    void sortColors(vector<int>& nums) {

        /*
        //approach 1 : SORTING 
        //T.C = O(n*log(n)) , S.C = O(1)

        sort(begin(nums), end(nums));
        */


        /*
        //approach 2: USING COUNTING
        //T.C : O(n+n) , S.C : O(1) 

        int n = nums.size();
        
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        
        for(int &num : nums) {
            if(num == 0)
                count_0++;
            else if(num == 1)
                count_1++;
            else
                count_2++;
        }
        
        for(int i=0; i<n; i++) {
            if(count_0 > 0) {
                nums[i] = 0;
                count_0--;
            } 
            else if(count_1 > 0) {
                nums[i] = 1;
                count_1--;
            } 
            else if(count_2 > 0) {
                nums[i] = 2;
                count_2--;
            }
        }
        */


        // approach 3
        //T.C : O(n) , S.C : O(1) 
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;

        for(int &num : nums) {
            if(num == 0)
                count_0++;
            else if(num == 1)
                count_1++;
            else
                count_2++;
        }

        int idx=0;
        for (int i = 0; i < count_0; i++) {
            nums[idx]=0;
            idx++;
        }
        for (int i = 0; i < count_1; i++) {
            nums[idx]=1;
            idx++;
        }
        for (int i = 0; i < count_2; i++) {
            nums[idx]=2;
            idx++;
        }


        /*
        //Approach-4 : Follow up / DNF algo(dutch national flag)
        //T.C : O(n) , S.C : O(1)

        int n = nums.size();
        
        int low = 0;   //denotes for 0
        int mid = 0;   //denotes for 1
        int high = n-1; //denotes for 2
        
        while (mid <= high) {
            if(nums[mid] == 1) {
                mid++;
            } 
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } 
            else { //nums[j] == 0
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
        }
        */
    }
};