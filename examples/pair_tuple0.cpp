/* Example showing how a few various features in C++14 work together: */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct some_data
{
 int x    = 0;
 string s = "data";
};

template <typename KeyType>
using data_map = unordered_map<KeyType, some_data>;

int main()
{
 data_map<string> d = {
		{ "key0", { 5, "some data" } },
		{ "key2", { 2, "some extra data" } },
		{ "key1", { 7, "some more data" } },
	};

 for(const auto& kv : d)
  cout << kv.first << ", " << kv.second.s << '\n';
}
