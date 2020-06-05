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
RESOURSES=$(wildcard $(RES_DIR)*.txt)
SOURCES=$(notdir $(wildcard $(SOURCES_DIR)*.cpp))
TESTS=$(notdir $(wildcard $(TEST_DIR)*.cpp))
OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)
EXECUTABLE=$(BIN_DIR)graph_tasks
TEST_EXECUTABLE=$(BIN_DIR)test

.PHONY : all clean example

all : $(EXECUTABLE) $(TEST_EXECUTABLE) example

clean :
	rm -rf $(OBJECTS_DIR)$(SOURCES_DIR)*.o \
	$(OBJECTS_DIR)$(TEST_DIR)*.o
	rm -rf $(EXECUTABLE) $(TEST_EXECUTABLE)
	rm -rf $(RES_DIR)*.txt

example :
ifeq ($(RESOURSES),)
	echo "4 0 2\n0 1 2\n0 2 2\n2 3 5" > $(RES_DIR)input.txt
	touch $(RES_DIR)output.txt
endif

$(EXECUTABLE) : $(addprefix $(OBJECTS_DIR)$(SOURCES_DIR), $(OBJECTS))
	$(CXX) $(LDFLAGS) $^ -o $@

$(TEST_EXECUTABLE) : $(addprefix $(OBJECTS_DIR)$(TEST_DIR), $(TEST_OBJECTS)) \
$(addprefix $(OBJECTS_DIR)$(SOURCES_DIR), $(filter-out main.o, $(OBJECTS)))
	$(CXX) $(LDFLAGS) $(INCLUDES) $^ -o $@

$(OBJECTS_DIR)$(SOURCES_DIR)%.o : $(SOURCES_DIR)%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJECTS_DIR)$(TEST_DIR)%.o : $(TEST_DIR)%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@