class Solution {
public:
    int maxArea(vector<int>& height) {
        //T.C. = O(n) , S.C. = O(1)
        
        int i = 0, j = height.size()-1;
        int max_area = 0;
        
        while (i<j){
            int w = j-i; //width
            int h = min(height[i], height[j]); //height
            
            int area = w*h;
            
            max_area = max(max_area, area);
            
            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return max_area;
    }
};