class Solution {
public:
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long,long>> v;
        for(int i=0;i<nums.size();i++) {
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        for(int i = 0; i<nums.size(); i++){

            for(int j = i+1; j<nums.size(); j++){
              
                long long int p = abs((v[i]).first-(v[j]).first);
               
                if(p<= t){
                    if(abs(v[i].second - v[j].second)<=k){
                      
                        return true;                        
                    }
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};