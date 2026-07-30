class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxscore = 0;
        int n = tokens.size();
        int i = 0;
        int j = n-1;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                power -= tokens[i];
                score++;
                maxscore = max(maxscore,score);
                i++;
            }
            else if(score>=1){
                power += tokens[j];
                score--;
                j--;
            }
            else return 0;
        }
        return maxscore;
    }
};