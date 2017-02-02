CXXFLAGS := -std=c++0x -Wall -Wextra -Werror

test: test.o game.o
	g++ $(CXXFLAGS) $(^) -o $(@)

game.o: game.cpp game.h
	g++ -c $(CXXFLAGS) $(<) -o $(@)

test.o: test.cpp game.h Catch/single_include/catch.hpp
	g++ -c $(CXXFLAGS) $(<) -o $(@)
