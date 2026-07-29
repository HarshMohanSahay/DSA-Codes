class Solution {
public:
    const long long LIM = 1000001;

    long long countPerm(vector<int>& cnt) {
        int n = 0;
        for (int x : cnt) n += x;

        long long ans = 1;
        int used = 0;

        for (int c : cnt) {
            for (int i = 1; i <= c; i++) {
                ans = ans * (used + i) / i;
                if (ans > LIM) ans = LIM;
            }
            used += c;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countPerm(half) < k) return "";

        string left = "";
        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countPerm(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};