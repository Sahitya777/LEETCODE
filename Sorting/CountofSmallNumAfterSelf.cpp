class Solution {
public:
    void mergetwo(vector<pair<int,int>>&mp,vector<int>&count,int si,int mid,int end){
        vector<pair<int,int>>temp(end-si+1);
        int i=si,j=mid+1,k=0;
        while(i<=mid && j<=end){
            if(mp[i].first>mp[j].first){
                count[mp[i].second] += end - j + 1;
                temp[k++]=mp[i++];
            }
            else{
                temp[k++]=mp[j++];
            }
            
        }
        while(i<=mid){
            temp[k++]=mp[i++];
        }
        while(j<=end){
            temp[k++]=mp[j++];
        }
        for(int p=0;p<k;p++){
            mp[p+si]=temp[p];
        }
    }
    void mergesort(vector<pair<int,int>>&mp,vector<int>&count,int si,int end){
        if(si>=end){
            return;
        }
        int mid=si+(end-si)/2;
        mergesort(mp,count,si,mid);
        mergesort(mp,count,mid+1,end);
        mergetwo(mp,count,si,mid,end);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={nums[i],i};
        }
        vector<int>count(n,0);
        mergesort(v,count,0,n-1);
        return count;
    }
};