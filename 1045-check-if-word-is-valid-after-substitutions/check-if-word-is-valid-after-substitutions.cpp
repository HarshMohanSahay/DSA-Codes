class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();
        for(int i =0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=3){
                char c = st.top();st.pop();
                char b = st.top();st.pop();
                char a = st.top();st.pop();

                if(a != 'a' ||  b != 'b' ||  c != 'c'){
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};