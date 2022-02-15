class Solution {
public:
    vector<string> split(const string &path) {
        vector<string> res = {};
        string temp = "";
        for (char ch : path) {
            if (ch == '/') {
                if (temp.size() > 0) {
                    res.push_back(temp);
                }
                temp = "";
            } else {
                temp += ch;
            }
        }
        return res;
    }
    
    
    string simplifyPath(string path) {
        // special: "/", "..", "."
        path += '/';
        vector<string> splits = split(path);

        vector<string> dir = {};
        for (string s : splits) {
            if (s == ".") {
                continue;
            } else if (s == "..") {
                if (!dir.empty()) {
                    dir.pop_back();
                }
            } else {
                dir.push_back(s);
            }
        }
        
        string res = "";
        for (auto str : dir) {
            res += ("/" + str);
        }
        return (res.empty()) ? "/" : res;
    }
    
};