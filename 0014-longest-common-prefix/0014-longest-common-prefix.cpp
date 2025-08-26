class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Take the first string as reference
        string prefix = strs[0];

        // Compare prefix with each string
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;

            // Check character by character
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }

        // Cut the prefix to the matched length
        prefix = prefix.substr(0, j);

        // If at any point prefix becomes empty, return ""
        if (prefix.empty()) return "";
    }

    return prefix;
    }
};