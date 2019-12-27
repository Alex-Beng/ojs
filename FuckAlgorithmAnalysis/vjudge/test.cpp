#include <iostream>
#include <string>
#include <set>
using namespace std;
 
struct intComp {
	bool operator() (const int& lhs, const int& rhs) const{
		return lhs > rhs;
	}
};
 
struct strComp
{
	bool operator() (const string& str1, const string& str2) const {
		return str1.length() < str2.length();
	}
};
 
int main() {
	int a[] = {10, 20, 30, 40, 50};
	set<int, intComp> s1(a, a + 5);
	for (auto it = s1.cbegin(); it != s1.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
 
	string b[] = {"apple", "banana", "pear", "orange", "strawberry"};
	set<string, strComp > s2(b, b + 5);
	for (auto it = s2.cbegin(); it != s2.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
