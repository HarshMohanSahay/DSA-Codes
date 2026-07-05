class Solution {
public:

    static bool cmp(pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]] +=1;
        }
        vector<pair<char,int>> v;


        for(auto it:mp){
            v.push_back(it);
        }

        sort(v.begin(),v.end(),cmp);

        string ans ="";

        for(auto it :v){
            ans.append(it.second,it.first);
        }

        return ans;



    }
};