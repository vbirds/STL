CC := g++  
CFLAGS := -g  
SRCS := $(wildcard *.cpp)  
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))  
TARGET  := $(patsubst %.o, %, $(OBJECTS))

all: $(OBJECTS) $(TARGET) 
	
%.o:%.cpp  
	$(CC) $(CFLAGS) -c $< -o $@ 
%:%.o
	$(CC) $(CFLAGS) $< -o $@  
clean:  
	rm -rf $(TARGET) $(OBJECTS)
