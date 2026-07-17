class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        long long ans = 0;
        long long sign = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '-'||s[i] == '+')) {
           if(s[i]=='-') sign = -1;
            i++;
        }

       
        while (i < n && s[i] <= '9' && s[i] >= '0') {
           ans = ans * 10 + (s[i] - '0');

            if(sign == 1 && ans > INT_MAX)
                return INT_MAX;

            if(sign == -1 && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign *ans;
    }
};