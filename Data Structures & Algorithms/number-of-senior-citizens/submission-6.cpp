class Solution {
public:
    int countSeniors(vector<string>& details) {
        int passengersAboveSixty = 0;
      
        for(string passenger : details)
        {
            if (passenger[11] > '6' || (passenger[11] == '6' && passenger[12] > '0'))
    passengersAboveSixty++;
        }
        
        return passengersAboveSixty;
    }
};