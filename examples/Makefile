
CXX=g++-6 

CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -fconcepts

CXXCC=$(CXX) $(CXXFLAGS)

all:	clean
	$(CXXCC) -o basic_raii0 basic_raii0.cpp
	$(CXXCC) -o deleter0 deleter0.cpp   
	$(CXXCC) -o dispatch0 dispatch0.cpp  
	$(CXXCC) -o pair_tuple0 pair_tuple0.cpp
	$(CXXCC) -o sum0 sum0.cpp

clean:
	rm -vf basic_raii0 deleter0 dispatch0 pair_tuple0 sum0
