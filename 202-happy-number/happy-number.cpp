class Solution {
public:
    int get(int n){
        int sum =0;
        int rem =0;
        while(n!=0){
            rem = n%10;
            n= n/10;
            sum += rem*rem;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = get(n);

        while(fast != 1 && slow !=fast){
            slow = get(slow);
            fast = get(get(fast));
        }
        return fast==1;
    }
};