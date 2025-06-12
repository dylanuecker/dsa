class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            vector<int> lps = computeLPSArray(words[i]);
            for (int j = 0; j < words.size(); ++j) {
                if (i == j) continue;
                if (isSubstringOf(words[i], words[j], lps)) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        } 
        return ans;
    }
private:
    vector<int> computeLPSArray(string &sub) {
        vector<int> lps(sub.size(), 0);
        int i = 1;
        int len = 0;
        while (i < sub.size()) {
            if (sub[i] == sub[len]) {
                ++len;
                lps[i] = len;
                ++i;
            } else {
                if (len > 0) len = lps[len - 1];
                else ++i;
            }
        }
        return lps;
    }
    bool isSubstringOf(string& sub, string& text, vector<int>& lps) {
        int i = 0;
        int j = 0;
        while (i < text.size()) {
            if (text[i] == sub[j]) {
                ++j;
                ++i;
                if (j == sub.size()) return true;
            } else {
                if (j > 0) j = lps[j - 1];
                else ++i;
            }
        }
        return false;
    }
};
