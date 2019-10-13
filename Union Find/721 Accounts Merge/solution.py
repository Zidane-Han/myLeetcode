class Solution:
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """

        def getRoot(i):
            while root[i] != i:
                root[i] = root[root[i]]
                i = root[i]
            return i

        length = len(accounts)
        root = list(range(length))

        dict = {}  # email: account id
        for i, account in enumerate(accounts):
            for email in account[1:]:
                if email not in dict:
                    dict[email] = i
                else:  # appear before
                    root[getRoot(i)] = getRoot(dict[email])

        dict_name = {}  # (rootid, account): emails
        for num in range(length):
            rootid = getRoot(num)
            name = accounts[num][0]
            if (rootid, name) in dict_name:
                dict_name[(rootid, name)] = dict_name[(rootid, name)] | {a for a in accounts[num][1:]}
            else:
                dict_name[(rootid, name)] = {a for a in accounts[num][1:]}  # email set

        res = []
        for k, v in dict_name.items():
            res.append([k[1]] + sorted(v))
        return res


if __name__ == '__main__':
    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"],
                ["John", "johnnybravo@mail.com"],
                ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
                ["Mary", "mary@mail.com"]]

    print(Solution().accountsMerge(accounts))
    print("result = ")
    print("[['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'], ['John', 'johnnybravo@mail.com'], ['Mary', 'mary@mail.com']]")