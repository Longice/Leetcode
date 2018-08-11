class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case ')':
                    if(!st.empty() && st.top() == '(') st.pop();
                    else return false;
                    break;
                case'}':
                    if(!st.empty() && st.top() == '{') st.pop();
                    else return false;
                    break; 
                case']':
                    if(!st.empty() && st.top() == '[') st.pop();
                    else return false;
                    break;
                default:
                    st.push(s[i]);
            }
        }
        if(st.empty())  return true;
        else return false;
    }
};
