class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        unordered_map<char, int> roman = {
            {'M', 1000}, {'D', 500}, {'C', 100},
            {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
        };
        for(int i=0; i<s.size(); i++){
            if(i + 1 < s.size() && roman[s[i]] < roman[s[i+1]]){
                total -= roman[s[i]];
            } else {
                total += roman[s[i]];
            }
        }
        return total;
    }
};