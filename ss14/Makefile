SUBMISSION = assX
EXECUTABLE = $(SUBMISSION)
SOURCES    = $(wildcard *.cpp)
OBJECTS    = $(patsubst %,%,${SOURCES:.cpp=.o})
CXX        = g++
CXXFLAGS   = -Wall -g -c -std=c++11 -o
LDFLAGS    = 
LDLIBS     =
#-------------------------------------------------------------------------------

#make executable
all: $(EXECUTABLE) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $@ $< -MMD -MF ./$@.d

#link Objects
$(EXECUTABLE) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

pluto:
	PATH=/opt/gcc482/bin:$(PATH);LD_LIBRARY_PATH=/opt/gcc482/lib:$(LD_LIBRARY_PATH);CXX=g++-482;make


#make clean
clean:
	rm -f ./*.o
	rm -f ./*.o.d
	rm -f $(EXECUTABLE)

#make cleanw for windows
cleanw :
	del /Q .\*.o
	del /Q .\*.o.d
	del /Q $(EXECUTABLE).exe

#make valgrind
valgrind:
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTABLE)

#make submission zip archive for PALME
submission:
	zip $(SUBMISSION).zip *.cpp *.h Makefile

.PHONY: clean cleanw submission

#The dependencies:
-include $(wildcard *.d)
