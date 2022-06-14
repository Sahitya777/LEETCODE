class Solution {
public:
bool solve(TreeNode* root,long min,long max){
        if(root==NULL)return true;
        if(root->val<=min||max<=root->val)return false;
        return solve(root->left,min,root->val)&&solve(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
       return solve(root,LONG_MIN,LONG_MAX);
    }
};