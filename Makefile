#flags passed to the g++ compiler
CXXFLAGS += -g -std=c++17
SOURCE_FILE += cd.cpp cdcatalogue.cpp

all:
  $(CXX) $(CXXFLAGS) -c $(SOURCE_FILE)
