class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k==n)return "0";
        stack<char>st;

        for(int i =0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.size()==0)return "0";

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        if (ans.empty())
            return "0";

        reverse(ans.begin(),ans.end());    
        return ans;

    }
};