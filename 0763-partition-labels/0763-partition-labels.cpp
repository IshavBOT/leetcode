class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int j=n-1;j>=0;j--){
            if(!mp.count(s[j])){
                mp[s[j]]=j;
            }
        }

        int idx=0;
        vector<int>ans;
        while(idx<n){
            int start=idx;
            int endIdx=mp[s[start]];

            while(idx<=endIdx){
                endIdx=max(endIdx,mp[s[idx]]);
                idx++;
            }

            int len=endIdx-start+1;
            ans.push_back(len);

        }

        return ans;
    }
};