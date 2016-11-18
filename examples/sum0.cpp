/* Summation: Simple example to show how a feature is improving as the
language standard moves forward. */

#include <iostream>

namespace cpp98 {

/* Note that in C++98 there's no way to directly deduce the 
type of ResultT: */

template <typename ResultT>
ResultT sum()
{
 return 0;
}

template <typename ResultT, typename X0>
ResultT sum(const X0 x0)	
{ 
 return x0 + sum<ResultT>(); 
}

template <typename ResultT, typename X0, typename X1>
ResultT sum(const X0 x0, const X1 x1)	
{ 
 return x0 + sum<ResultT>(x1); 
}

template <typename ResultT, typename X0, typename X1, typename X2>
ResultT sum(const X0 x0, const X1 x1, const X2 x2)	
{ 
 return x0 + sum<ResultT, X1, X2>(x1, x2); 
}

// Note: No variadic templates-: you'll need more expansion each time!

} // namespace cpp98

namespace cpp11 {

auto sum(void) -> decltype(0)
{
 return 0;
}

template <typename X0>
auto sum(const X0 x0) -> decltype(x0 + sum())
{
 return x0 + sum();
}

template <typename X0, typename X1>
auto sum(const X0 x0, const X1 x1) -> decltype(x0 + x1)
{
 return x0 + sum(x1);
}

template <typename X0, typename ...XS>
auto sum(const X0 x0, const XS ...xs) -> decltype(x0 + sum(xs...))
{
 return x0 + sum(xs...);
}

} // namespace cpp11

namespace cpp14 {

auto sum(void)
{
 return 0;
}

template <typename X0, typename ...XS>
auto sum(const X0 x0, const XS ...xs)
{
 return x0 + sum(xs...);
}

} // namespace cpp14

namespace cpp17 {

template <typename ...XS>
auto sum(const XS ...xs)
{
 return (xs + ... + 0);
}

} // namespace cpp17

namespace cpp17c {

// note: Haskell: sum xs = foldr (+) 0 xs
auto sum(const auto ...xs)
{
 return (xs + ... + 0);
}

} // namespace cpp17c

namespace cpp17c2 {

// Unrestricted parameters (not in slides):
auto sum(const auto ...xs)
{
 return (... + xs);
}

} // namespace cpp17c

int main()
{
 using std::cout;

 cout << cpp98::sum<int>(1) << '\n';
 cout << cpp98::sum<int>(1, 2) << '\n';
 cout << cpp98::sum<int>(1, 2, 3) << '\n';

 cout << cpp11::sum(1) << '\n';
 cout << cpp11::sum(1, 2) << '\n';
 cout << cpp11::sum(1, 2, 3) << '\n';

 cout << cpp14::sum(1) << '\n';
 cout << cpp14::sum(1, 2) << '\n';
 cout << cpp14::sum(1, 2, 3) << '\n';

 cout << cpp17::sum(1) << '\n';
 cout << cpp17::sum(1, 2) << '\n';
 cout << cpp17::sum(1, 2, 3) << '\n';

 cout << cpp17c::sum(1) << '\n';
 cout << cpp17c::sum(1, 2) << '\n';
 cout << cpp17c::sum(1, 2, 3) << '\n';

 // FREE Bonus (!):
 auto strs = [](auto const* ...xs) { return (std::string(xs) + ...); };
 cout << cpp17c2::sum(strs("Hi ", "there ", "world!\n"));
}

