class Solution {
public:
    void helper(TreeNode* &root,int val){
        if(root==NULL){
            TreeNode* ans=new TreeNode(val);
            root=ans;
            return;
        }
        if(val<root->val){
            helper(root->left,val);
        }
        else{
            helper(root->right,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root,val);
        return root;
    }
};

