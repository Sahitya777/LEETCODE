class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        
        if(nums.size() == 0)return ans;                
        
        int size = nums.size();                       
        sort(nums.begin() ,nums.end());                 
        
        
        for(int i = 0 ; i<=size-4 ; i++)
        {
            for(int j = i+1 ; j<=size-3 ; j++)
            {
                int left = j+1 , right = size-1;
                long long tar = nums[i]+nums[j];
                
                while(left < right )
                {
                    long long sum = nums[left ]+nums[right];
                    if( (sum + tar) < (long long)target ) left++;               
                    else if((sum+tar) > (long long)target ) right--;        
                    else{
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        ans.push_back(v);
                        while(left < right && nums[left]==v[2])left++;       
                        while(left < right && nums[right]==v[3])right--;        
                    }
                    
                }
                while(j<size-3 && nums[j+1]==nums[j])j++;           
            }
            while(i<size-4 && nums[i+1]==nums[i])i++;               
        }
        return ans;                                                
    }
    
};
