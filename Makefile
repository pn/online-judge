CFLAGS=-g -Wall
SOURCES := $(wildcard *.c)
PROGS := $(patsubst %.c, %, $(SOURCES))
TESTS := $(patsubst %.c, %.test, $(SOURCES))
all: $(PROGS)

%:%.c
	$(CC) $(CFLAGS) -o $@ $<

#TODO: this rule is not working - does not rebuild programs for out files
%.out: %

%.out: %.in %.ans
	./$* < $*.in > $*.out

test: $(TESTS)
%.test: %.out %.ans
	diff $^ > $@ || cat $@ && false

.PHONY: all tests clean
.DELETE_ON_ERROR: $(TESTS)
clean:
	-rm $(PROGS) *.out *.test
