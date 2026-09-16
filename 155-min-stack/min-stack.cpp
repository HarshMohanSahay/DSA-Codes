class MinStack {
public:
typedef long long ll;
stack<ll>st;
ll mini ;

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) {
        st.push(value);
        mini = value;
        }
        else if(value>mini){
            st.push(value);
        }
        else{
            st.push(2ll*value-mini);
            mini = value;
        }


    }

    
    void pop() {
        if(st.empty()) return ;
        ll x = st.top();
        st.pop();

        if(x<mini){
            mini = 2ll*mini-x;
        }
    }
    
    int top() {
        
        ll x = st.top();
        if(mini<x)return x;
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */