# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

# Main program
MAIN_SRC = library.cpp
MAIN_TARGET = library_system

# Test program
TEST_SRC = test.cpp
TEST_TARGET = test_library_system
TEST_LIBS = -lcatch2

# Default target
all: $(MAIN_TARGET) $(TEST_TARGET)

# Main target
$(MAIN_TARGET): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(MAIN_SRC)

# Test target
$(TEST_TARGET): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC) $(TEST_LIBS)

# Clean up
clean:
	rm -f $(MAIN_TARGET) $(TEST_TARGET)
