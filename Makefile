CXX=g++
CXXFLAGS=-Wall -Werror -c --std=c++17
LDFLAGS=
VPATH=src test object/src object/test thirdparty
SOURCES_DIR=src/
TEST_DIR=test/
OBJECTS_DIR=object/
BIN_DIR=bin/
INCLUDES=-I thirdparty -I src
SOURCES=$(notdir $(wildcard $(SOURCES_DIR)*.cpp))
TESTS=$(notdir $(wildcard $(TEST_DIR)*.cpp))
OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)
EXECUTABLE=graph_tasks
TEST_EXECUTABLE=test

.PHONY : all clean

all : $(BIN_DIR)$(EXECUTABLE) $(BIN_DIR)$(TEST_EXECUTABLE)

clean :
	rm -rf $(OBJECTS_DIR)$(SOURCES_DIR)*.o $(OBJECTS_DIR)$(TEST_DIR)*.o \
	$(BIN_DIR)$(EXECUTABLE) $(BIN_DIR)$(TEST_EXECUTABLE)

$(BIN_DIR)$(EXECUTABLE) : $(addprefix $(OBJECTS_DIR)$(SOURCES_DIR), $(OBJECTS))
	$(CXX) $(LDFLAGS) $^ -o $@

$(BIN_DIR)$(TEST_EXECUTABLE) : $(addprefix $(OBJECTS_DIR)$(TEST_DIR), $(TEST_OBJECTS)) \
$(addprefix $(OBJECTS_DIR)$(SOURCES_DIR), $(filter-out main.o, $(OBJECTS)))
	$(CXX) $(LDFLAGS) $(INCLUDES) $^ -o $@

$(OBJECTS_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@