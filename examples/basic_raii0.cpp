/* "noisy" classes like these can be helpful in understanding construction/destruction
behavior. Suggested experiments:
	- what happens if an instance of S is a member? ie.:
		struct outer_class {
			S s;
		};
		...have outer_class print something on destruction as well.
	- implement:
		default, copy, move ctors, and assignment that also print something
		experiment with those in different situations

	- what happens if a pointer to something is held?
*/

#include <vector>
#include <iostream>

using namespace std;

struct S
{
 ~S() { cout << "S::~S()\n"; }
};

int main()
{
 {
 S s;
 } // s goes out of scope right here

 cout << "===========" << endl;

 {
 vector<S> vs(5);
 } // vs, and thus all s instances contained in it

 cout << "===========" << endl;
}
