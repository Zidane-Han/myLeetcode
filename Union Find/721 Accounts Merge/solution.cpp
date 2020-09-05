/*
 *
 * [721] Accounts Merge
 */

// dict{email:account_id}. If email appeared, merge ids.<=> root(A1)=A2
// dict{account_id : emails}
// output
class Solution {
private:
    int getRoot(int node) {
        while (root[node] != node) {
            node = root[node];
        }
        return node;
    }

public:
    vector<int> root;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        for (int m = 0; m < len; m++) {
            root.push_back(m);
        }
        
        unordered_map<string, int> email_id_table;  // {email : account_id}
        for (int k = 0; k < len; k++) {
            vector<string> account = accounts[k];
            for (int i = 1; i < account.size(); i++) {
                if (email_id_table.count(account[i]) == 0) {
                    // not appear before
                    email_id_table[account[i]] = k;
                } else {
                    // appeared before, then union accounts
                    root[getRoot(k)] = getRoot(email_id_table[account[i]]);
                }
            }
        }

        unordered_map<int, set<string>> id_email_table;
        for (auto it : email_id_table) {
            int root_tmp = getRoot(it.second);
            if (id_email_table.count(root_tmp) == 0) {
                id_email_table[root_tmp] = {it.first};
            } else {
                id_email_table[root_tmp].insert(it.first);
            }
        }

        vector<vector<string>> res;
        for (auto itr : id_email_table) {
            vector<string> tmp = {accounts[itr.first][0]};
            // add set at the end of vector
            tmp.insert(tmp.end(), itr.second.begin(), itr.second.end());
            res.push_back(tmp);
        }
        return res;
    }
};