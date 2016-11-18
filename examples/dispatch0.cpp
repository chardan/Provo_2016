/* Simple study in function dispatch. Notice that the heavy lifting is almost entirely
embedded into the type system, declaratively. */

#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <unordered_map>

struct context
{
 std::vector<std::string> params = { "Hi", "there!" };
};

bool fn0(const context ctx)
{
 for(const auto& s : ctx.params)
  std::cout << s << '\n';

 return true;
}

using dispatch_fn  = std::function<bool(context)>;
using dispatch_map = std::unordered_map<std::string, dispatch_fn>;

int main()
{
 dispatch_map cmds = { { "show", fn0 } };

 context c;
 std::cout << cmds["show"](c) << '\n';
}
