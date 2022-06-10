class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* ptr=head;
        vector<int>vs;
        while(ptr!=NULL){
            vs.push_back(ptr->val);
            ptr=ptr->next;
        }
        ListNode* temp=head;
        sort(vs.begin(),vs.end());
        for(int i=0;i<vs.size();i++){
            temp->val=vs[i];
            temp=temp->next;
        }
        return head;
    }
};