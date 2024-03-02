CXX=g++
CXXFLAGS=-g -Wall -std=c++11

OBJS=wire.o gate.o circuit.o logicsim.o

all: logicsim

# Rule to build the executable
logicsim: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Generic rule to compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Dependency rules
logicsim.o: wire.h gate.h circuit.h 
wire.o: wire.h 
gate.o: wire.h
circuit.o: wire.h gate.h event.h

clean:
	rm -f *.o logicsim

