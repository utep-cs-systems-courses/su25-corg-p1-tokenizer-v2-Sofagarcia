#list of object files for this lab
OBJS = tokenizer.o history.o uimain.o

#compiler flags: -g for debugging, -03 for opt
CFLAGS = -g -O3

#default target to build
all: tokenizer

#tokenizer depends on all object files
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

#remove all generated object files and the final executable
clean:
	rm -f *.o tokenizer

#run the program after building it
run: tokenizer
	./tokenizer
