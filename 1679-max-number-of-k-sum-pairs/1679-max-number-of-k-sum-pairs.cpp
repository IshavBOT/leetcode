class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int rem=k-nums[i];
            if(mp.count(rem)){
                ans++;
                mp[rem]--;
                if(mp[rem]==0){
                    mp.erase(rem);
                }
                
            }else{
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};