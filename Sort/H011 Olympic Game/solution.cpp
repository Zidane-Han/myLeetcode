#include <vector>
#include <algorithm>

struct CountryInfo{
	string countryName;
	int gold;
	int silver;
	int bronze;
};

bool Compare(CountryInfo first, CountryInfo second)
{
	if (first.gold != second.gold) return first.gold > second.gold;
	if (first.silver != second.silver) return first.silver > second.silver;
	if (first.bronze != second.bronze) return first.bronze > second.bronze;
	if (first.countryName != second.countryName) return first.countryName < second.countryName;
	return false;
}

int main()
{
	int n;
	cin >> n;
	CountryInfo temp;
	vector<CountryInfo> countries;
	
	for (int i = 0; i < n; i++) {
		countries.push_back(temp);
	}
	
	sort(countries.begin(), countries.end(), Compare);
	for (auto i: countries) {
		cout << i.countryName << endl;
	}
	
	return 0;
}