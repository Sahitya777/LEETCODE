class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int f=0;
        vector<int>freq (26,0);
        for(int i=0;i<s.size();i++){
            f=max(f,++freq[s[i]-'A']);
            if(ans-f<k){
                ans++;
            }
            else{
                freq[s[i-ans]-'A']--;
            }
        }
        return ans;
    }
};




