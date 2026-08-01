class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = height.size()-1;
        int leftmax = height[0];
        int rightmax = height[n-1];
        int ans = 0;
        while(i<j){
            if(height[i]<height[j]){
                i++;
                leftmax = max(leftmax,height[i]);
                ans += leftmax-height[i];
            }
            else{
                j--;
                rightmax = max(rightmax,height[j]);
                ans += rightmax-height[j];
            }
        }
        return ans;
    }
};