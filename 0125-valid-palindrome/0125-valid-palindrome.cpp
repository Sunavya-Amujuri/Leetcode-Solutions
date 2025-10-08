class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        string result = "";

        for(int i=0; i<len; i++){
            if(isalnum(s[i])){
                result += tolower(s[i]);
            }
        }
        int n = result.size();
        for(int i=0; i<n / 2; i++){
            if(result[i] != result[n-1-i]){
                return false;
                break;
            }
        }
        return true;
    }
};