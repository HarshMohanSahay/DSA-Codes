class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxcount = 0;
        //int n = log2(pow(10,7))+1;
        for(int i =0 ; i<32 ;i++){
            int countone = 0;
            for (auto & candidate : candidates){
                if((candidate & (1<<i))>0){
                    countone++;
                }
            }
            maxcount = max(maxcount,countone);
        }
        return maxcount;
    }
};