class Solution {
public:
    void solve(TreeNode* root,vector<vector<int>> &temp){
        if(root==NULL){
            return;
        }
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<int>ans;
        s1.push(root);
        while(!s1.empty()){
            while(!s1.empty()){
                TreeNode* front=s1.top();
                s1.pop();
                ans.push_back(front->val);
                if(front->left){
                    s2.push(front->left);
                }
                if(front->right){
                    s2.push(front->right);
                }
            }
            temp.push_back(ans);
            ans.clear();
            while(!s2.empty()){
                TreeNode* front=s2.top();
                s2.pop();
                ans.push_back(front->val);
                if(front->right!=NULL){
                    s1.push(front->right);
                }
                if(front->left!=NULL){
                    s1.push(front->left);
                }
            }
            if(ans.empty()){
                continue;
            }
            temp.push_back(ans);
            ans.clear();
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        solve(root,v);
        return v;
    }
};