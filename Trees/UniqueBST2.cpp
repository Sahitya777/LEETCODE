class Solution {
public:
    vector<TreeNode*> solve(int start,int end){
        vector<TreeNode*>ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start;i<=end;i++){
            auto left=solve(start,i-1);
            auto right =solve(i+1,end);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* temp= new TreeNode(i,l,r);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return vector<TreeNode*>();
        }
        return solve(1,n);
    }
};