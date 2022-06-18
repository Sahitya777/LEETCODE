class Solution {
public:

vector<vector<int>>arr;
int target;
int check(TreeNode *root, vector<int>& res, int &sum){
    res.push_back(root->val);
    sum += root->val;
    if((root->left == NULL )&&(root->right==NULL)){
        if(sum == target){
            arr.push_back(res);
        }
        return root->val;
    }
    if(root->left){    
        int x=check(root->left,res,sum);
        res.pop_back();  
        sum-=x;
    } 
    if(root->right){
        int x=check(root->right,res,sum);
        res.pop_back();
        sum-=x;
    }        
    return root->val;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(!root)return arr;
    target = targetSum;
    vector<int>res;
    int sum=0;
    check(root,res,sum);
    return arr;
}
};