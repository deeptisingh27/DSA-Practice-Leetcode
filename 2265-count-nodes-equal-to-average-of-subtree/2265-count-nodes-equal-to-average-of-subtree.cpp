/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSum(TreeNode* root, int &count) {
        if(!root) return 0;
        
        count++;
        
        int left = findSum(root->left, count);
        int right = findSum(root->right, count);
        
        return left + right + root->val;
    }
    
    void solve(TreeNode* root, int &ans) {
        if(!root) return;
        
        int count = 0;
        int totalSum = findSum(root, count);
        
        if((totalSum)/count == root->val) {
            ans++;
        }
        
        solve(root->left, ans);
        solve(root->right, ans);        
    }

    pair<int, int> solvee(TreeNode* root, int &ans){
        if(!root) return {0, 0};

        pair<int, int> P1 = solvee(root->left, ans);
        pair<int, int> P2 = solvee(root->right, ans);

        int totalSum = P1.first + P2.first + root->val;
        int totalCount = P1.second + P2.second + 1;

        int avg = totalSum / totalCount;

        if(avg == root->val){
            ans += 1;
        }

        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        //Approach-1 Brute Force
        //T.C = O(n^2) for every root, we visit it's subtree to find average
        //S.C = O(1) (excluding recursion stack space)

        /*
        int ans = 0;
        
        solve(root, ans);
        
        return ans;
        */


        //Approach-2 (Doing postorder traversal)
        //T.C = O(n)
        //S.C = O(1) (excluding recursion stack space)
        
        int ans = 0;
        
        solvee(root, ans);
        
        return ans;
    }
};