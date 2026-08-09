class Solution {
public:
    int smallestNumber(int n, int t) {
        int mul = 1;
        int m = n;
        int count=0;
        int lastdigit = 0;
        while(n!=0){
            mul *= n%10;
            n = n/10;

        }
        if(mul%t == 0) return m;
        else{
            while(mul%t!=0){
                
                lastdigit = m%10;
                mul=mul/lastdigit;
                m++;
                lastdigit=m%10;
                mul=mul*lastdigit; 
            }
        }
        return m ;

    }
};