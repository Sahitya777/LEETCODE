class Solution {
public:
    vector<int>vs;
    int i=0;
    void inorder1(TreeNode* root){
        if(!root){
            return;
        }
        inorder1(root->left);
        vs.push_back(root->val);
        inorder1(root->right);
    }
    
    void inorder2(TreeNode* root){
        if(!root){
            return;
        }
        inorder2(root->left);
        root->val=vs[i];
        i++;
        inorder2(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder1(root);
        sort(vs.begin(),vs.end());
        inorder2(root);
    }
};