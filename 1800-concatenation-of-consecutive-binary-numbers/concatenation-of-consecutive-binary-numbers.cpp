class Solution {
public:
    int concatenatedBinary(int n) {
        long result = 0;
        int M = 1e9+7;
        for(int i =1;i<=n;i++){
            int noofbits = log2(i)+1;
            result = ((result<<noofbits)%M + i)%M;
        }
        return  result;
    }
};