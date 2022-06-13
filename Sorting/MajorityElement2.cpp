class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        set<int>ss;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>n/3){
                ss.insert(nums[i]);
            }
        }
        vector<int>vs(ss.begin(),ss.end());
        return vs;
    }
};