class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int leftmax = 0;
        int rightmax = 0;
        int ans = 0;
        while(i<j){
          leftmax = max(leftmax,height[i]);
          rightmax = max(rightmax,height[j]);
          if(leftmax<rightmax){
            ans+=leftmax-height[i];
            i++;
          }
          else{
            ans+=rightmax-height[j];
            j--;
          }

        }
        return ans;
    }
};