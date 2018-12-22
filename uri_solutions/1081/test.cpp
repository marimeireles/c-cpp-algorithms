#include <set>
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
	vector<set<int>> a;
	a.resize(1);
	a[0].insert(1); a[0].insert(2); a[0].insert(3); a[0].insert(2);
	for (int s : a[0]) {
		cout << s << endl;
	}
	return 0;
}

