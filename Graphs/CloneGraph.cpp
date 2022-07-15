class Solution {
public:
    Node* dfs(Node* curr,unordered_map<Node*,Node*>& mp){
        vector<Node*>vc;
        Node* clone=new Node(curr->val);
        mp[curr]=clone;
        for(auto it: curr->neighbors){
            if(mp.find(it)!=mp.end()){
                vc.push_back(mp[it]);
            }
            else{
                vc.push_back(dfs(it,mp));
            }

        }
        clone->neighbors=vc;
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        if(node==NULL){
            return NULL;
        }
        if(node->neighbors.size()==0){
            Node* clone=new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
        
    }
};