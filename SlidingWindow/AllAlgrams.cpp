class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>stored (26,0);
        vector<int>temp (26,0);
        if(s.length()<p.length()){
            return ans;
        }
        for(int i=0;i<p.length();i++){
            temp[s.at(i)-'a']++;
            stored[p.at(i)-'a']++;
        }
        for(int i=0;i+p.length()<s.length()+1;i++){
            if(temp==stored){
                ans.push_back(i);
            }
            temp[s.at(i)-'a']--;
            if(i+p.length()<s.length()){
                temp[s.at(i+p.length())-'a']++;
            }
        }
        return ans;
    }
};
