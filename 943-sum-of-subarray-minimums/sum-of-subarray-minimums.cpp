class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n, -1);
        vector<int> right(n, n);

        stack<int> st;

        
       

      

        // Next smaller or equal element
        for(int i = 0; i <n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                right[st.top()] = i;
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
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;

            long long contribution =
                (long long)arr[i] * leftChoices * rightChoices;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};
