class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int totalcomb = (1<<k);
        string str = "";
        unordered_set<string>result;
        for(int i =k;i<=s.size();i++){
            
            str = s.substr(i-k,k);
            if(!result.count(str)){
            result.insert(str);
            totalcomb--;}

            if(totalcomb==0) return true;


        }
        return false;
    }
};