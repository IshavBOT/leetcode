class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        int maxLen=0;

        while(j<n){
            if(nums[j]==0){
                count++;
            }

            if(count>k){
                while(count>k){
                    if(nums[i]==0){
                        count--;
                    }
                    i++;
                }
            }

            if(count<=k){
                int len=j-i+1;
                maxLen=max(maxLen,len);
            }

            j++;
        }
        return maxLen;
    }
};