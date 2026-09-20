class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xornum = 0;
        for(auto &num : nums){
            xornum ^= num;
        }
        long long  mask= xornum & (-xornum);
        int groupa = 0;
        int groupb = 0 ;

        for(auto &num: nums){
            if(num & mask){
                groupa ^= num;
            }
            else{
                groupb ^= num;
            }
        }
        return {groupa,groupb};
    }
};