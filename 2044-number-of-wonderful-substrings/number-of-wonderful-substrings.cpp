class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll>mp;
        mp[0]=1;
        int cumxor = 0;
        ll result = 0;

        for(char &ch : word){
            cumxor = cumxor ^ (1<<(ch-'a'));
            result += mp[cumxor];

            for(char ch1 = 'a';ch1<='j';ch1++){
                int changexor = cumxor ^ (1<<(ch1-'a'));
                result += mp[changexor];
            }
            mp[cumxor]++;
        }
        return result;
    }
};