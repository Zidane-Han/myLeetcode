class Solution {
private:
    string compactLine(const vector<string>& line, const int word_len, const int maxWidth) {
        if (line.size() == 1) {
            return line[0] + string(maxWidth - line[0].size(), ' ');
        }
        
        int avgSpace = (maxWidth - word_len) / (line.size() - 1);
        string avgsubstr = string(avgSpace, ' ');
        int addSpace = (maxWidth - word_len) % (line.size() - 1);
        
        string str = "";
        for (int i = 0; i < line.size() - 1; i++) {
            str += line[i];
            str += avgsubstr;
            if (addSpace) {
                str += ' ';
                addSpace--;
            }
        }
        str += line.back();
        
        return str;
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int len = 0;    // total length of words in a line
        vector<string> l = {};
        for (auto word : words) {
            if (len + l.size() + word.size() > maxWidth) {
                res.push_back(compactLine(l, len, maxWidth));
                len = 0;
                l.clear();
            }
            
            len += word.size();
            l.push_back(word);
        }
        
        // proc the last line
        string str = "";
        for (int i = 0; i < l.size() - 1; i++) {
            str += (l[i] + ' ');
        }
        str += l.back();
        while (str.size() < maxWidth) {
            str += ' ';
        }
        
        res.push_back(str);
        
        return res;
    }
};