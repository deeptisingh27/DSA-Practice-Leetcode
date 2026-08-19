class Solution {
    public int[] replaceElements(int[] arr) {

        //T.C = O(n) , S.C = O(1)

        int n = arr.length;
        int maxi = -1;

        for(int i=n-1 ; i>=0 ; i--){
            int curr = arr[i];
            arr[i] = maxi;
            maxi = Math.max(maxi, curr);
        }

        return arr;
    }
}