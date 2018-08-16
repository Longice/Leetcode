class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int m = haystack.size(), n=needle.size();
        for(int i = 0; i < m; ++i){
            int j;
            for(j = 0; j < n; ++j){
                if(i + j >= m) return -1;
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == n) return i;
        }
        return -1;
    }
};
