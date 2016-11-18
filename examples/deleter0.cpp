/* Example showing a deleter being used to help interface with C: */

#include <cstdio>
#include <vector>
#include <memory>

using namespace std;

using file_ptr = unique_ptr<FILE, decltype(&fclose)>;

auto write_things(const vector<char>& things) 
{
 // Real-world programs should check for errors:
 auto fp = file_ptr(fopen("data.dat", "w"), &fclose);		

 return fwrite(things.data(), things.size(), 1, fp.get());
}

int main()
{
 write_things({ 'a', 'b', 'c', 'd', 'e' });
}

