class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Step 2: sort using custom comparator
        sort(strNums.begin(), strNums.end(), [](string &a, string &b) {
            return a + b > b + a;  // "9" + "34" = "934" > "349" = "34" + "9"
        });

        if (strNums[0] == "0") return "0";

        // Step 4: concatenate result
        string result;
        for (string &s : strNums) {
            result += s;
        }

        return result;
    }
};