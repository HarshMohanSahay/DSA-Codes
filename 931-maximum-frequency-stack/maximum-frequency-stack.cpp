class FreqStack {
    typedef pair<int, pair<int, int>> p;

    priority_queue<p, vector<p>> pq;
    unordered_map<int, int> mp;
    int position = 0;

public:
    void push(int val) {
        mp[val]++;
        position++;

        pq.push({mp[val], {position, val}});
    }

    int pop() {
        int x = pq.top().second.second;
        pq.pop();
        mp[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */