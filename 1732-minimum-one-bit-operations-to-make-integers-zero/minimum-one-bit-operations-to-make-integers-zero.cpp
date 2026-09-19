class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        vector<long long>f(32);
        f[0]=1;
        for(int i =1;i<32;i++){
            f[i]=2*f[i-1]+1;
        }
        int result = 0;
        int sign = 1;

        for(int i =31;i>=0;i--){
            if((n&(1<<i))!=0){
                if(sign==1){
                    result+=f[i];
                }
                else{
                    result-=f[i];
                }
                sign = sign*(-1);
            }
        }
        return result;
    }
};