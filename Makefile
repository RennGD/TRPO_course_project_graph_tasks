CXX=g++
CXXFLAGS=-c -Wall
LDFLAGS=
VPATH=src object
SOURCES_DIR=src/
SOURCES=main.cpp connect.cpp
OBJECTS_DIR=object/
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/graph_tasks

.PHONY : all clean

all : $(EXECUTABLE)

clean:
	rm $(OBJECTS_DIR)*.o

$(EXECUTABLE) : $(addprefix $(OBJECTS_DIR), $(OBJECTS))
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJECTS_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@