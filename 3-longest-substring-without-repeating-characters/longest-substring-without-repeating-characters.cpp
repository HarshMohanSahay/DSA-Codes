class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxlength = 0;
        int len = 0;
        unordered_set<char>st;
       for(right =0;right<s.length();right++){
        while(st.find(s[right])!=st.end()){
            st.erase(s[left]);
            left++;
            
        }
        st.insert(s[right]);
        len = right-left+1;
        maxlength = max(maxlength,len);
       }

    return maxlength;


    }
};