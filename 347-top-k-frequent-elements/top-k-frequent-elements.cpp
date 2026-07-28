class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<p,vector<p>> pq;

        for(auto it : mp){
            pq.push({it.second,it.first});

        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};