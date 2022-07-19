class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,t=0;
        int maxnum=0;
        map<char,int>mp;
        for(i=0;i<n;i++){
            if(mp.count(s[i]) && mp[s[i]] >= t){
                maxnum=max(maxnum,i-t);
                t=mp[s[i]]+1;
                mp.erase(s[i]);
                mp[s[i]]=i;
            }
            else{
                mp[s[i]]=i;
            }
        }
        return maxnum>i-t?maxnum:i-t;
    }
};