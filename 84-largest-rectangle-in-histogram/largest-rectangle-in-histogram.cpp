class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> right(n, n);
        vector<int> left(n, -1);

        // right smaller

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        // left smaller
          for(int i =n-1;i>=0;i--){
                   while(!st.empty()&& heights[st.top()]>heights[i]){
                       left[st.top()]= i;
                       st.pop();
                   }
                   st.push(i);
               }
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currarea = heights[i] * width;
            maxarea = max(maxarea, currarea);
        }
        return maxarea;
    }
};