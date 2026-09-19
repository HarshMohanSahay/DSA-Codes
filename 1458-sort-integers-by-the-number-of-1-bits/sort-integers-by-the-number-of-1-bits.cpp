class Solution {
public:
    static bool comp(int &a,int &b){
        int noof1ina = __builtin_popcount(a);
            int noof1inb = __builtin_popcount(b);
            if(noof1ina == noof1inb) return a<b;
            return noof1ina < noof1inb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        

        
        sort(begin(arr),end(arr),comp);
        return arr;
    }
};