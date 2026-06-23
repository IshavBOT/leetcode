class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int minLen=INT_MAX;
        int sum=0;

        while(j<n){
            sum+=nums[j];

            if(sum<target){
                j++;
            }

            else if(sum>=target){
                while(sum>=target){
                    minLen=min(minLen,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        if(minLen==INT_MAX) return 0;

        return minLen;

    }
};