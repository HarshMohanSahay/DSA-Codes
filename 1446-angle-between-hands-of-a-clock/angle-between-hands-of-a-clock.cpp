class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourdegree = (hour*30)%360;
        double mindegree = fmod(minutes*5.5,360);
        double ans = abs(hourdegree-mindegree);
        return min(ans,360-ans) ;
    }
};