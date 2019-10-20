src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = 
CC = g++

filereader: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) filereader
