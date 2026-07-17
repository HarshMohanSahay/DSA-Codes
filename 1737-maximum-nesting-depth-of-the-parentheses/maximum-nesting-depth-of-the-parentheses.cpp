class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int i =0;
        int n = s.size();
        int cnt=0;
        int maxi=0;
        while(i<n){
            if(s[i]=='('){ 
                cnt++;
                st.push(s[i]);
                i++;
                maxi = max(maxi,cnt);
                }


            else if(s[i]=='+' || s[i]=='-'||s[i]== '*'||s[i]== '/'||s[i]<='9'&&s[i]>='0'){
                i++;
            }
            else{
                st.pop();
                i++;
                cnt--;
            }
            
        }
        return maxi;
        
    }
};