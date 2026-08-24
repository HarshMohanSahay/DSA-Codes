class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int k =0;k<32;k++){
            int counzeros=0;
            int countones = 0;
            for(int num:nums){
                if((num & (1<<k))==0) counzeros++;
                else countones++;
            }
            if(countones%3==1)
            result = result|(1<<k);
        }
        return result;
    }
};