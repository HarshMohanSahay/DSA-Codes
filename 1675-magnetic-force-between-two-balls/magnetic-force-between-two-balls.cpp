class Solution {
public:
    bool ispossibletoplace(int midf,vector<int>&position,int m){
        int prev = position[0];
        int currball = 1;
        for(int i =1;i<position.size();i++){
            int curr = position[i];
            if((curr-prev)>=midf){
                currball++;
                prev = curr;
            }
            if(currball==m)break;
        }
        return (currball==m) ;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int minf = 1;
        int maxf = position[n-1]-position[0];
        int ans = 0;

        while(minf<=maxf){
            int midf = minf+(maxf-minf)/2;
            if(ispossibletoplace(midf,position,m)){
                ans = midf;
                minf = midf+1;
            }
            else{
                maxf=midf-1;
            }
        }
        return ans;
    }
};