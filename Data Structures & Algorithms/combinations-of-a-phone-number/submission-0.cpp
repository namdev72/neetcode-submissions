#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void fun(int idx, string& digits, vector<string>& ans, string& path, unordered_map<char, string>& mp) {
        if (idx == digits.length()) {
            ans.push_back(path);
            return;
        }
        
        string str = mp[digits[idx]];
        for (int i = 0; i < str.length(); i++) {
            path.push_back(str[i]);
            fun(idx + 1, digits, ans, path, mp);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> ans;
        string path = "";
        fun(0, digits, ans, path, mp);
        return ans;
    }
};