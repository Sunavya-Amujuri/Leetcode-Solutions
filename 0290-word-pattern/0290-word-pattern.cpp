class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        size_t start = 0;
        size_t end = s.find(' ');

        while(end != string::npos){
            words.push_back(s.substr(start, end-start));
            start = end+1;
            end = s.find(' ', start);
        }
        words.push_back(s.substr(start));

        int n = pattern.size();
        int m = words.size();

        if(n != m)return false;

        unordered_map<char, string> patternToWord;
        unordered_map<string, char> wordToPattern;

        for (int i = 0; i < n; i++) {
            char ch = pattern[i];
            string word = words[i];

            // If pattern letter already mapped, verify same word
            if (patternToWord.count(ch)) {
                if (patternToWord[ch] != word)
                    return false;
            }
            // If word already mapped, verify same pattern letter
            else if (wordToPattern.count(word)) {
                if (wordToPattern[word] != ch)
                    return false;
            }
            // Otherwise, create a new mapping
            else {
                patternToWord[ch] = word;
                wordToPattern[word] = ch;
            }
        }

        return true;
    
        
    }
};