class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        int ans=0;
        int sign=1;
        stack<int>stk;
        for(int i=0;i<n;i++){
            if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(isdigit(s[i])){
                long long temp=0;
                while(i<n && isdigit(s[i])){                
                    temp=temp*10+s[i]-'0';
                    i++;
                }
                i--;
                ans=ans+sign*temp;
            }
            else if(s[i]=='('){
                stk.push(ans);
                stk.push(sign);
                ans=0;
                sign=1;
            }
            else if(s[i]==')'){
                int curr_sign=stk.top();
                stk.pop();
                int curr_val=stk.top();
                stk.pop();
                ans=ans*curr_sign+curr_val;
            }
        }
        return ans;
    }
};