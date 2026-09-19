class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftcount =0;

        while(right>left){
          right = right &(right-1);
        }

        return right;
    }
};