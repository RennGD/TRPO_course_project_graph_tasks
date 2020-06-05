CXX=g++
CXXFLAGS=-Wall -Werror -c --std=c++17
LDFLAGS=
VPATH=src test object/src object/test thirdparty
SOURCES_DIR=src/
TEST_DIR=test/
OBJECTS_DIR=object/
BIN_DIR=bin/
RES_DIR=resourses/
INCLUDES=-I thirdparty -I src
SOURCES=$(notdir $(wildcard $(SOURCES_DIR)*.cpp))
TESTS=$(notdir $(wildcard $(TEST_DIR)*.cpp))
OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)
EXECUTABLE=$(BIN_DIR)graph_tasks
TEST_EXECUTABLE=$(BIN_DIR)test

.PHONY : all clean

all : $(EXECUTABLE) $(TEST_EXECUTABLE)

clean :
	rm -rf $(OBJECTS_DIR)$(SOURCES_DIR)*.o \
	$(OBJECTS_DIR)$(TEST_DIR)*.o
	rm -rf $(EXECUTABLE) $(TEST_EXECUTABLE)

$(EXECUTABLE) : $(addprefix $(OBJECTS_DIR)$(SOURCES_DIR), $(OBJECTS))
	$(CXX) $(LDFLAGS) $^ -o $@

$(TEST_EXECUTABLE) : $(addprefix $(OBJECTS_DIR)$(TEST_DIR), $(TEST_OBJECTS)) \
$(addprefix $(OBJECTS_DIR)$(SOURCES_DIR), $(filter-out main.o, $(OBJECTS)))
	$(CXX) $(LDFLAGS) $(INCLUDES) $^ -o $@

$(OBJECTS_DIR)$(SOURCES_DIR)%.o : $(SOURCES_DIR)%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJECTS_DIR)$(TEST_DIR)%.o : $(TEST_DIR)%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@