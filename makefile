EXECUTABLE 	= main.exe

CXX	= g++

TESTSOURCES = $(wildcard test*.cpp)
TESTS       = $(TESTSOURCES:%.cpp=%)

# list of sources used in project
SOURCES 	= $(wildcard *.cpp)
SOURCES     := $(filter-out $(TESTSOURCES), $(SOURCES))
# list of objects used in project
OBJECTS		= $(SOURCES:%.cpp=%.o)
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp
