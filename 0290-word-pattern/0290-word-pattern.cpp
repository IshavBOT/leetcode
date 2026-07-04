class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>str;
        int n=s.size();
        int i=0;
        while(i<s.length()){
            while(s[i]==' ' && i<n){
                i++;
            }

            int start=i;
            while(s[i]!=' ' && i<n){
                i++;
            }

            string subString=s.substr(start,i-start);
            str.push_back(subString);
        }

        if(str.size()!=pattern.size()){
            return false;
        }

        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;

        int size=pattern.size();

        for(int i=0;i<size;i++){
            if(mp1.count(pattern[i]) && mp1[pattern[i]]!=str[i]){
                return false;
            }

            if(mp2.count(str[i]) && mp2[str[i]]!=pattern[i]){
                return false;
            }

            mp1[pattern[i]]=str[i];
            mp2[str[i]]=pattern[i];
        }

        return true;


    }
};