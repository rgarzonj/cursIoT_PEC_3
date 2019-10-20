src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = 

filereader: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) filereader