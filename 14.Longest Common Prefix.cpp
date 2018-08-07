class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size() == 0)
            return prefix;
        if(strs.size() == 1)
            return strs[0];
        int pos = 0;
        if(pos >= strs[0].size())
            return prefix;
        while(1){
            for(int i = 1; i < strs.size(); ++i){
                if(pos < strs[i].size()){
                    if(strs[i][pos] != strs[i-1][pos])
                        return prefix;
                }else {
                    return prefix;
                }
            }
            prefix += strs[0][pos++];
        } 
    }
};
