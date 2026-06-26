class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int maxLen=0;
        unordered_map<char,int>mp;
        int maxFrequency=INT_MIN;

        while(j<n){
            mp[s[j]]++;
            for(auto it:mp){
                maxFrequency=max(maxFrequency,it.second);
            }

            int windowSize=j-i+1;
            int minFreq=windowSize-maxFrequency;

            if(minFreq>k){
                while(minFreq>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(mp.find(s[i]));
                    }
                    i++;
                    maxFrequency=0;

                    for(auto it:mp){
                        maxFrequency=max(it.second,maxFrequency);
                    }
                    minFreq=j-i+1-maxFrequency;
                }
            }

            int len=j-i+1;
            maxLen=max(maxLen,len);
            j++;

        }
        return maxLen;
    }
};