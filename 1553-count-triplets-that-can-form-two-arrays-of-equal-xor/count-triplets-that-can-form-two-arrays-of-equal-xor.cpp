class Solution {
public:
    int countTriplets(vector<int>& arr) {
      
     vector<int>prefixor(arr.begin(),arr.end());
     prefixor.insert(prefixor.begin(),0);
       int n = prefixor.size();
     for(int i =1;i<n;i++){
        prefixor[i] = prefixor[i] ^ prefixor[i-1];
     }
     int triplets = 0;
     for(int i = 0;i<n;i++){
        for(int k = i+1 ;k<n; k++){
            if(prefixor[k]==prefixor[i]){
                triplets += k-i-1;
            }
        }
     }
     return triplets;
    }
};