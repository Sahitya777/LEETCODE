class Solution {
public:
    int len(ListNode* head){

        int l=0;
        while(head!=NULL){
            l=l+1;
            head=head->next;
        }
        return l;
    }
    TreeNode* bst(ListNode* &head,int length){
        if(length<=0){
            return NULL;
        }
        TreeNode* l=bst(head,length/2);
        TreeNode* root=new TreeNode(head->val);
        root->left=l;
        head=head->next;
        root->right=bst(head,length-(length/2)-1);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int length=len(head);
        return bst(head,length);
    }
};
