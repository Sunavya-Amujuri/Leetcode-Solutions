class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        string result = "";

        for(int i=0; i<len; i++){
            if(isalnum(s[i])){
                result += s[i];
            }
        }

        for(int i=0; i<result.size(); i++){
            result[i] = tolower(result[i]);
        }

        for(int i=0; i<result.size() / 2; i++){
            if(result[i] != result[result.size()-1-i]){
                return false;
                break;
            }
        }
        return true;
    }
};