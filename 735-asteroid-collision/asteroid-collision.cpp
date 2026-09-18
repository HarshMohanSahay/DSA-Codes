class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        list<int> st;

        for(int i = 0; i < n; i++) {

            // Positive asteroid → no collision with previous asteroids
            if(arr[i] > 0) {
                st.push_back(arr[i]);
            }
            else {

                // Current asteroid is negative
                while(!st.empty() &&
                      st.back() > 0 &&
                      st.back() < abs(arr[i])) {

                    st.pop_back();
                }

                // Equal size → both destroyed
                if(!st.empty() &&
                   st.back() == abs(arr[i])) {

                    st.pop_back();
                }

                // Current asteroid survives
                else if(st.empty() || st.back() < 0) {
                    st.push_back(arr[i]);
                }

                // Otherwise st.back() > abs(arr[i])
                // Current asteroid is destroyed
            }
        }

        vector<int> ans(st.begin(), st.end());

        return ans;
    }
};