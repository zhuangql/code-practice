#include <iostream>
#include <sstream>
#include<map>

using namespace std;

template<typename T>
struct sort
{
	bool operator()(T const& key1, T const& key2) const {
		return key1 > key2;
	}
};

class test
{
	map<int, string, sort<int>> mapp;
	void haha(){
		map<int,string,sort<int>> aaaa;
	}
};
int main()
{
	std::map<int ,string, sort<int>> digit_roman_map;
	digit_roman_map[100] = "qqq";
	digit_roman_map[50] = "www";
	digit_roman_map[10] = "eee";
	for(auto const a : digit_roman_map){
		cout << a.first <<endl;
	}
	return 0;

	istringstream istr;
	istr.str("1 56.7");
	//上述两个过程可以简单写成 istringstream istr("1 56.7");
	cout << istr.str() << endl;
	int a;
	float b;
	istr >> a;
	cout << a << endl;
	istr >> b;
	cout << b << endl;
    int qqq;
    stringstream os;
    os << 2.1474836491;
    os >> qqq;
    cout << qqq;
    cout << os.str();
    //printf("=====%d", 2.78);
	return 0;
}