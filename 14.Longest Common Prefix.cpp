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


// 分治法
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        return longestCommonPrefix(strs, 0, strs.size()-1);
    }
    
    string longestCommonPrefix(vector<string>& strs, int l, int r){
        if(l == r)
            return strs[l];
        else{
            int m = (l + r) / 2;
            string lcpLeft = longestCommonPrefix(strs, l, m);
            string lcpRight = longestCommonPrefix(strs, m+1, r);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    
    string commonPrefix(string left, string right){
        int length = min(left.size(), right.size());
        for(int i = 0; i < length; ++i){
            if(left[i] != right[i])
                return left.substr(0, i);
        }
        return left.substr(0, length);
    }
};
