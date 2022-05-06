class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int>stk;
        for(int i=0;i<s.length();i++){
            if(i==0 || s[i]!=s[i-1]){
                stk.push(1);
            }
            else if(++stk.top()==k){
                stk.pop();
                s.erase(i-k+1,k);
                i=i-k;
            }
        }
        return s;
    }
};