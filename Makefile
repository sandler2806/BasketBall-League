#!make -f
# This Makefile can handle any set of cpp and hpp files.
# To use it, you should put all your cpp and hpp files in the SOURCE_PATH folder.
CXX2=clang++-9
CXXFLAGS2=-std=c++2a


CXX=clang++-9
CXXVERSION=c++2a
SOURCE_PATH=sources
OBJECT_PATH=objects
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

run: test

test: TestRunner.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Renana Rimon
StudentTest1.cpp:
	curl https://raw.githubusercontent.com/renanarimon/cpp_5b_test/master/Test.cpp > $@

# Shauli Taragin
StudentTest2.cpp:
	curl https://raw.githubusercontent.com/ShauliTaragin/Orgchart-A/main/Test.cpp > $@

# Dvir Gev
StudentTest3.cpp:
	curl https://raw.githubusercontent.com/dvirGev/CPP--Ex5-par1/main/Test.cpp > $@

main: main.o $(OBJECTS)
	$(CXX2) $(CXXFLAGS2) $^ -o $@

main.o: main.cpp
	$(CXX2) $(CXXFLAGS2) --compile $< -o $@

tidy:
	clang-tidy $(HEADERS) $(TIDY_FLAGS) --

valgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f $(OBJECTS) *.o test*
	rm -f StudentTest*.cpp
