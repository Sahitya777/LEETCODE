class Solution {
public:
    bool isvalid(string &s){
        if(s.length()!=1 || s[0]<'0' || s[0]>'9'){
            return false;
        }
        return true;
    }
    string decodeString(string s) {
        stack<string>stk;
        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i] == ']'){
                string r="";
                while(!stk.empty() && stk.top()!="["){
                    r=stk.top()+r;
                    stk.pop();
                }
                if(!stk.empty()){
                    stk.pop();
                }
                string num="";
                while(!stk.empty() && isvalid(stk.top())){
                    num=stk.top()+num;
                    stk.pop();
                }
                int inum=stoi(num);
                string res="";
                for(int i=0;i<inum;++i){
                    res+=r;
                }
                stk.push(res);
            }
            else{
                string t="0";
                t[0]=s[i];
                stk.push(t);
            }
        }
        while(!stk.empty()){
            ans=stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};