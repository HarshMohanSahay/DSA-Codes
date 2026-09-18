class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> leftsm(n, -1);
        vector<int> rightsm(n, n);
        vector<int> leftgt(n, -1);
        vector<int> rightgt(n, n);

        stack<int> st;
        // Next smaller or equal element
        for(int i = 0; i <n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                rightsm[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
          while(!st.empty()) {
            st.pop();
        }
        // Previous smaller element
         for(int i = n-1; i >=0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                leftsm[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
          while(!st.empty()) {
            st.pop();
        }

         for(int i = 0; i <n; i++) {

            while(!st.empty() && arr[st.top()] < arr[i]) {
                rightgt[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
          while(!st.empty()) {
            st.pop();
        }
        // Previous smaller element
         for(int i = n-1; i >=0; i--) {

            while(!st.empty() && arr[st.top()] <= arr[i]) {
                leftgt[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long leftChoicessm = i - leftsm[i];
            long long rightChoicessm = rightsm[i] - i;

            long long leftChoicesgt = i - leftgt[i];
            long long rightChoicesgt = rightgt[i] - i;

            long long contributionsm =
                (long long)arr[i] * leftChoicessm * rightChoicessm;

            long long contributiongt =
                (long long)arr[i] * leftChoicesgt * rightChoicesgt;    

            ans = (ans + (contributiongt - contributionsm)) ;
        }

        return ans;
    }
    
};
