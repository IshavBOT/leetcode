class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        vector<int>greater(n2);
        stack<int>s;

        for(int i=n2-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }

            if(s.empty()){
                greater[i]=-1;
            }else{
                greater[i]=s.top();
            }

            s.push(nums2[i]);
        }

        unordered_map<int,int>mp;
        for(int i=0;i<n2;i++){
            mp[nums2[i]]=greater[i];
        }

        vector<int>ans;
        for(int num:nums1){
            ans.push_back(mp[num]);
        }

        return ans;
    }
};