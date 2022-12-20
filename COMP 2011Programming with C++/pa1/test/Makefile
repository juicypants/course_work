LD_FLAGS=-Wl,--allow-multiple-definition

all: test

%.o: %.cpp
	g++ -std=c++11 -o $@ -c $<

pa1_nomain.o: pa1.o
	objcopy --redefine-sym main=replaced_main $< $@

test: pa1_nomain.o tester.o
	g++ -o $@ $^ $(LD_FLAGS)

clean:
	rm -f *.o *.out
