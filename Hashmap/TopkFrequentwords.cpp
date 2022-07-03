class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> counts;
        
        for(string s: words){
            counts[s]++;
        }
        
        vector<vector<string>> bucket(words.size()+1);
        for(pair<string,int> a: counts){
            bucket[a.second].push_back(a.first);
        }
        
        vector<string> result(k);
        int temp = 0;
        for(int i=words.size();i>=0;i--){
		   
            sort(bucket[i].begin(),bucket[i].end());
            for(int j=0;j<bucket[i].size();j++){
                if(temp == k)
                    return result;
                result[temp++] = bucket[i][j];
            }
        }
        
        return result;
    }
};