class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int maxLen=0;

        while(j<n){
            mp[s[j]]++;

            if(mp.size()!=j-i+1){
                while(mp.size()!=j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(mp.find(s[i]));
                    }
                    i++;
                }
            }

            int len=j-i+1;
            maxLen=max(maxLen,len);
            j++;
        }
        return maxLen;
    }
};